#include <iostream>
#include <sstream>
#include "overload.hpp"

bool Player::CanJump() {
    return true;
}

void Player::Chat(const char *raw) {
    auto ok = std::string(raw);
    std::istringstream iss(ok);

    std::string cmd;
    iss >> cmd;
    std::string arg;
    iss >> arg;
    if (cmd == "jump")
        m_jumpSpeed = std::atof(arg.c_str());
    else if (cmd == "speed")
        m_walkingSpeed = std::atof(arg.c_str());
}

void BearChest::AddBear(class Bear *) {
    printf("AddBear\n");
}

void Bear::OnPrepareAttack(class Actor *) {
    printf("OnPrepareAttack\n");
}

void BearChest::Tick(float) {
    printf("Tick \n");
    if (m_bears.size() != 0)
        return;
    for (auto ok : m_playerTimeLeft) {
        printf("%f for %s\n", ok.second, ok.first.Get()->GetPlayerName());
        ok.second -= 1;
    }

}

float Bear::GetAggressionRadius() {
    printf("GetAggressionRadius\n");
    return 0.0;
}

bool BearChest::IsArmedStage() {
    printf("IsArmedStage\n");
    return false;
}

bool BearChest::IsEliteStage() {
    printf("IsEliteStage\n");
    return false;
}
bool Bear::CanBeArmed() {
    printf("CanUse\n");
    return false;
}

void Bear::AttackForChest(class IPlayer *) {
    printf("AttackForChest\n");
}

void Bear::Init() {
    printf("Init\n");
}

class Actor *BearSpawner::Spawn() {
    printf("Spawn\n");
    return new Bear();
}

size_t BearSpawner::GetMaxActors() {
    printf("GetMaxActors\n");
    return 2;
}
void BearDefendChestState::EnterState(class Actor *) {
    printf("EnterState\n");
}