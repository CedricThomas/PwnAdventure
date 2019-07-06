from pygdbmi.gdbcontroller import GdbController
import re
import os
import time

class CPPClass:

    def __init__(self, name):
        self.name = name
        self.content = None

def writeCommand(gdbmi, command, timeout=0):
    resp = gdbmi.write(command)

    time.sleep(timeout)

    elems = []
    content_end = False
    content_start = False
    while not content_end or not content_start:
        for elem in resp:
            if elem['payload'] != None:
                content_start = True
                elems.append(elem)
            elif elem['payload'] == None and content_start == True:
                content_end = True
        resp = gdbmi.write('', timeout_sec=5)
    return elems

def getIncludesFiles(gdbmi):
    include_folder_regex = ".*GameLogic\/.*\.h"
    exlude_folder_regex = ".*\.\..*"

    response = writeCommand(gdbmi, 'info sources')

    payload = response[4]['payload']
    headers = payload.split(',')
    headers = [header for header in headers if re.match(include_folder_regex, header)]
    headers = [os.path.basename(header) for header in headers if not re.match(exlude_folder_regex, header)]
    return headers

def getTypesOfIncludes(gdbmi, headers):
    response = writeCommand(gdbmi, 'info types', 5)

    map = dict()
    check = 0
    filename = ""
    for line in response:
        line = line['payload']
        detection = line.strip("\t\n ;:").replace("\\n", "").replace("\\t", "")
        if check == 0: # File extract
            line = line.strip("\t\n ;:").replace("\\n", "").replace("\\t", "")
        elif detection == "File":
            line = "File"
        elif check == 1: # File name
            line = line[:-3]
            if "Include/" in line or "./" in line:
                line = line.split("/")[1]
        elif check == 2:
            line = line.split(":", 1)[1].replace("\\n", "").replace("\\t", "").replace(";", "")

        if line == "File":
            check = 1
        elif check == 1 and line in headers:
            filename = line
            map[filename] = []
            check = 2
        elif check == 1 and line not in headers:
            check = 0
        elif check == 2:
            map[filename].append(line)
    for key, items in map.items():
        map[key] = [CPPClass(item) for item in items if "typedef" not in item]
    return map

def enrichIncludes(gdbmi, structured_includes):
    for key, types in structured_includes.items():
        for class_type in types:
            response = writeCommand(gdbmi, 'ptype ' + class_type.name)

            start = False
            for resp in response:
                if "type = " in resp["payload"]:
                    class_type.content = resp["payload"][len("type = "):]
                    start = True
                elif start:
                    class_type.content += resp["payload"]
            class_type.content = class_type.content.replace("\\n", "\n")
    return structured_includes

def saveEnrichedIncludes(dirName, enriched_includes):
    if not os.path.exists(dirName):
        os.mkdir(dirName)
    for filename, contents in enriched_includes.items():
        file_path = os.path.join(dirName, filename)
        with open(file_path, 'w') as f:
            content = '\n'.join((elem.content for elem in contents))
            f.write(content)

PID = input("Enter the process PID :")

gdbmi = GdbController(gdb_args=["--nx", "--quiet", "--interpreter=mi2", "--pid=" + PID])
print(gdbmi.get_subprocess_cmd())
writeCommand(gdbmi, '')

includes = getIncludesFiles(gdbmi)

structured_includes = getTypesOfIncludes(gdbmi, includes)

enriched_includes = enrichIncludes(gdbmi, structured_includes)

saveEnrichedIncludes("headers", enriched_includes)
