#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int raider(int k) {
  srand(time(NULL));
  return rand() % k;
}
int skills(int l) {
  srand(time(NULL));
  return rand() % l;
}
int creacts(int y) {
  srand(time(NULL));
  return rand() % y;
}
int raidresult(int r) {
  srand(time(NULL));
  return rand() % r;
}
int toss(int n) {
  srand(time(NULL));
  return rand() % n;
}

char player1Name[10], player2Name[10], player3Name[10], player4Name[10],
    player5Name[10], player6Name[10], player7Name[10];

int Toss, choice, playerSkill1,
    played = 0, won = 0, lost = 0, playAgain, Raider, compReaction, urReaction,
    result_1, result_2, score1 = 0, score2 = 0, raidNum = 1, playerSkill2;

int main() {

  printf("\n\n\t\t\t\tWELCOME TO THE WORLD OF KABADDI \n");
  printf("\n");
  for (int j = 0; j < 89; j++) {
    printf("_");
  }
  printf("\n");
  for (int i = 0; i < 25; i++) {
    printf("|           |       |                       |                      "
           " |       |           |\n");
  }

  for (int j = 0; j < 89; j++) {
    printf("-");
  }
  printf("\n");
playagain:
  if (playAgain == 1) {
    score1 = 0;
    score2 = 0;
    raidNum = 1;
  }

  printf("\nEnter your Playing-7\n");
  printf("Player-1: ");
  scanf("%s", player1Name);
  printf("Player-2: ");
  scanf("%s", player2Name);
  printf("Player-3: ");
  scanf("%s", player3Name);
  printf("Player-4: ");
  scanf("%s", player4Name);
  printf("Player-5: ");
  scanf("%s", player5Name);
  printf("Player-6: ");
  scanf("%s", player6Name);
  printf("Player-7: ");
  scanf("%s", player7Name);

  printf("TIME FOR TOSS..!!\n\nPRESS 0 FOR 'HEADS' & 1 FOR 'TAILS'\n");
  scanf("%d", &Toss);
  if (Toss == toss(2)) {
    printf("PRESS 1 FOR 'COURT' & 0 FOR 'RAID'\n");
    scanf("%d", &choice);
    if (choice == 0) {
      printf("You will RAID first.!\n");
    } else if (choice == 1) {
      printf("COMPUTER will RAID first.!\n");
      goto cmpraid;
    }
  } else {
    printf("You will RAID first.!\n");
  }

// raid first
matchOn:
printf("\ncomputer %d - %d you\n",score2,score1);

  printf("\nIt is raid number %d \n", raidNum);
  raidNum = raidNum + 1;
  // Raider = raider(7);
  printf("Select player's number to send him as raider.\n");
  scanf("%d", &Raider);
  // you
  
  switch (Raider - 1) {
  case 0:
    printf("\n%s is going for the raid..! ", player1Name);
    goto skill;
    break;

  case 1:
    printf("\n%s is going for the raid..! ", player2Name);
    goto skill;
    break;

  case 2:
    printf("\n%s is going for the raid..! ", player3Name);
    goto skill;
    break;

  case 3:
    printf("\n%s is going for the raid..! ", player4Name);
    goto skill;
    break;

  case 4:
    printf("\n%s is going for the raid..! ", player5Name);
    goto skill;
    break;

  case 5:
    printf("\n%s is going for the raid..! ", player6Name);
    goto skill;
    break;

  case 6:
    printf("\n%s is going for the raid..! ", player7Name);
    goto skill;
    break;
  }

skill:
  playerSkill1 = skills(5);

  // for skill
  switch (playerSkill1) {
  case 0:
    printf("and tries for 'TURNING HAND TOUCH', and ");
    goto reaction;
    break;
  case 1:
    printf("and attempts a 'RUNNING HAND TOUCH', and ");
    goto reaction;
    break;
  case 2:
    printf("and goes for the 'TOE TOUCH', and ");
    goto reaction;
    break;
  case 3:
    printf("and here he tries the 'SCORPION KICK', and  ");
    goto reaction;
    break;
  case 4:
    printf("and surprisingly attempts 'RUNNING KICK' in the middle of the "
           "COURT, and ");
    goto reaction;
    break;
  }

reaction:
  compReaction = creacts(6);
  switch (compReaction) {
  case 0:
    printf(" the defender goes for 'DOUBLE THIGH HOLD'. ");
    goto result1;
    break;
  case 1:
    printf(" defender tries 'ANKLE HOLD' here. ");
    goto result1;
    break;
  case 2:
    printf(" the defenders came in with a 'CHAIN' to block the raider, ");
    goto result1;
    break;
  case 3:
    printf(" the defence goes for a 'DASH' ");
    goto result1;
    break;
  case 4:
    printf(" here defender tries the 'BACK HOLD' ");
    goto result1;
    break;
  }

result1:
  result_1 = raidresult(8);

  // for result1
  switch (result_1) {
  case 0:
    printf(" the raider escapes easily and got 1 point.\n");
    score1 = score1 + 1;
    goto cmpraid;
    break;
  case 1:
    printf(" the defender don't let the raider escape and earns one point for "
           "his team..!\n");
    score2 = score2 + 1;
    goto cmpraid;
    break;
  case 2:
    printf(" the raider get rid of the two defenders and added 2 more points "
           "to the total.\n");
    score1 = score1 + 2;
    goto cmpraid;
    break;
  case 3:
    printf(" JUST AMAZINGGG..!!, the defence is 'ROARING', 1 point to the "
           "defence.\n");
    score2 = score2 + 1;
    goto cmpraid;
    break;
  case 4:
    printf(" a good effort from raider and the defence, 'AN EMPTY RAID' this "
           "time.\n");
    goto cmpraid;
    break;
  case 5:
    printf(" 'ONE POINT EACH', raider got the 'BONUS' but can not escape the "
           "'SOLID DEFENCE'.\n");
    score1 = score1 + 1;
    score2 = score2 + 1;
    goto cmpraid;
    break;
  case 6:
    printf(" this is a 'SUUUUUPPPEEERRRRRRR RAAAIIIIIID..!!' the RAIDER "
           "manages to escape all the '3 DEFENDERS'; got 3 POINTS.\n");
    score1 = score1 + 3;
    goto cmpraid;
    break;
  case 7:
    printf(
        " the defence got him, raider was just about to cross the midline but "
        "the support comes at very right time, 1 POINT to the defence.\n");
    score2 = score2 + 1;
    goto cmpraid;
    break;
  }

cmpraid:
printf("\ncomputer %d - %d you\n",score2,score1);
  printf("\nIt is raid number %d\n", raidNum);
  raidNum = raidNum + 1;
  playerSkill2 = skills(4);
  switch (playerSkill2) {
  case 0:
    printf(" It's time for computer to raid and computer tries for 'TURNING "
           "HAND TOUCH', and ");
    goto reaction2;
    break;
  case 1:
    printf(" It's time for computer to raid and computer attempts a 'RUNNING "
           "HAND TOUCH', and ");
    goto reaction2;
    break;
  case 2:
    printf(" It's time for computer to raid and computer goes for the 'TOE "
           "TOUCH', and ");
    goto reaction2;
    break;
  case 3:
    printf(" It's time for computer to raid and computer here he tries the "
           "'SCORPION KICK', and  ");
    goto reaction2;
    break;
  }

reaction2:
  urReaction = creacts(5);

  // for reactions
  switch (urReaction) {
  case 0:
    printf(" the defender goes for 'DOUBLE THIGH HOLD'. ");
    goto result2;
    break;
  case 1:
    printf(" defender tries 'ANKLE HOLD' here. ");
    goto result2;
    break;
  case 2:
    printf(" the defenders came in with a 'CHAIN' to block the raider, ");
    goto result2;
    break;
  case 3:
    printf(" the defence goes for a 'DASH' ");
    goto result2;
    break;
  case 4:
    printf(" here defender tries the 'BACK HOLD' ");
    goto result2;
    break;
  case 5:
    printf(" defender tries to trap the raider in 'THIGH HOLD' ");
    goto result2;
    break;
  }

result2:
  result_2 = raidresult(7);

  switch (result_2) {
  case 0:
    printf(" JUST AMAZINGGG..!!, the defence is 'ROARING', 1 point to the "
           "defence.\n");
    score1 = score1 + 1;
    break;
  case 1:
    printf(" the raider get rid of the two defenders and added 2 more points "
           "to the total.\n");
    score2 = score2 + 2;
    break;
  case 2:
    printf(" the defender don't let the raider escape and earns one point for "
           "his team..!\n");
    score1 = score1 + 1;
    break;
  case 3:
    printf(" the raider escapes easily and got 1 point.\n");
    score2 = score2 + 1;
    break;
  case 4:
    printf(" this is a 'SUUUUUPPPEEERRRRRRR RAAAIIIIIID..!!' the RAIDER "
           "manages to escape all the '3 DEFENDERS'; got 3 POINTS.\n");
    score2 = score2 + 3;
    break;
  case 5:
    printf(
        " the defence got him, raider was just about to cross the midline but "
        "the support comes at very right time, 1 POINT to the defence.\n");
    score1 = score1 + 1;
    break;
  case 6:
    printf(" 'ONE POINT EACH', raider got the 'BONUS' but can not escape the "
           "'SOLID DEFENCE'.\n");
    score2 = score2 + 1;
    score1 = score1 + 1;
    break;
  }

  if (raidNum > 31) {
    goto matchOver;
  } else {
    goto matchOn;
  }

matchOver:
  for (int i = 0; i < 90; i++) {
    printf("_");
  }

  // final result
  if (score1 > score2) {
    won = won + 1;
    played = played + 1;
    printf("\n\n\t\t\t     'CONGRATULATIONS..!!' YOU WON THE MATCH.\n");
  } else if (score2 > score1) {
    lost = lost + 1;
    played = played + 1;
    printf("\n\n\t\t\t     'WELL TRIED..!' YOU LOST THE MATCH.\n");
  } else {
    played = played + 1;
    printf("\n\n\t\t\t     'THIS MATCH ENDS ON A TIE..! CONGRATULATIONS TO "
           "BOTH THE TEAMS.'\n");
  }
  printf("\t\t\t\t\tTHE FINAL SCORE\n\t\t\t\t     COMPUTER %d - %d "
         "YOU\n\t\t\t\tPLAYED %d \tWON %d \tLOST %d\n\n",
         score2, score1, played, won, lost);

  for (int i = 0; i < 90; i++) {
    printf("_");
  }

  printf("\n\t\t\tPress\t\t 0 to QUIT\t\t1 to PLAY AGAIN\n");
  scanf("%d", &playAgain);
  if (playAgain == 1) {
    goto playagain;
  } else {
    goto quit;
  }
quit:
  printf("\n\t\t\tSEE YOU AGAIN.... KABADDI LOVER..!\n\n\n");
  return 0;
}