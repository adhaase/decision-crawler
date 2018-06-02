# C++ Automated Dungeon Crawler
#### by Alex Haase

## Introduction
This dungeon crawler is a C++ automated decision game formatted as a classic level based simulation. The player (you!) is given 4 skill based attributes (Vitality, Attack, Agility, Luck) and given 25 points to add to the skill categories. Execution is determined based on your decisions

From there a simulation will run, and based on your choices the hero either lives to the end of the simulation (Floor 10 of the dungeon) or dies. Best of luck!

## Skill Traits
The player is defaulted to 5 skill points in each of the mentioned categories (apart from Vitality, which is 25). An additional 25 is given to spend throughout each category, with the goal of buffing your player correctly to allow for completion of the puzzle. There are many efficient combinations! Keep trying!

**VITALITY**: Your health pool, when this falls to 0, you die. You start with a default health of 25 HP.

**ATTACK**: How much damage you do to enemies. The faster you kill incoming enemies, the faster you can proceed with the dungeon.

**AGILITY**: Increases your evasiveness allowing you to avoid enemies. Doesn't matter how much damage the enemies do if they can't hit ya!

**LUCK**: Increases your ability to find new items and tools allowing you to progress through the dungeon faster.

Current **prototype** of the skill distribution/customization system. The dungeon system is currently being worked on.
![decision crawler prototype](https://user-images.githubusercontent.com/9776844/40870199-5de2345c-65f8-11e8-9536-1201d0a54770.PNG)
