#include <stdio.h>
#include <stdlib.h>
#include "skilltree.h"
#include "player.h"


int main(){

    FILE *FSkill;
    BinTree Skill = Nil;
    int STR = 0;
    int DEF = 0;
    LoadSkillTree(&Skill,FSkill);
    AmbilSkill(&Skill,&STR,&DEF);
    PrintSkillTree(Skill,2);
    printf("%d %d", STR,DEF);
    SaveSkillTree(Skill,FSkill);

    return 0;
}

