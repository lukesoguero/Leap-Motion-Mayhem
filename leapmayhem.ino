/*

*/
// Setup pins
int led_a = 2;
int led_b = 3;
int led_c = 4;
int led_d = 5;
int led_e = 6;
int s_1 = 7;
int s_2 = 8;
int s_3 = 9;
int s_4 = 10;
int life_1 = 11;
int life_2 = 12;
int life_3 = 13;
bool hasEnemy = false;
int enemy = 0;
int enemyArray[] = {led_a, led_b, led_c, led_d, led_e};
int lives = 3;
int score = 0;



void setup() {
  
    Serial.begin(9600);
    delay(100);
    pinMode(led_a, OUTPUT);
    pinMode(led_b, OUTPUT);
    pinMode(led_c, OUTPUT);
    pinMode(led_d, OUTPUT);
    pinMode(led_e, OUTPUT);
    pinMode(s_1, OUTPUT);
    pinMode(s_2, OUTPUT);
    pinMode(s_3, OUTPUT);
    pinMode(s_4, OUTPUT);
    pinMode(life_1, OUTPUT);
    pinMode(life_2, OUTPUT);
    pinMode(life_3, OUTPUT);
    initializeLives();
    
}

void loop() {
  if(!hasEnemy) {
    enemy = generateEnemy();
  }
  
  while(Serial.available() > 0) {
     
    char command = Serial.read();
    
    switch (command) {
      case 'a':
        // statements
        if (enemy == 1) {
          digitalWrite(led_a, LOW);
          digitalWrite(led_b, LOW);
          digitalWrite(led_c, LOW);
          digitalWrite(led_d, LOW);
          digitalWrite(led_e, LOW);
          hasEnemy = false;
          deathAnimation(enemy);
        }
        else {
          incomingFire();
        }
        break;
      case 'b':
        // statements
        if (enemy == 2) {
          digitalWrite(led_a, LOW);
          digitalWrite(led_b, LOW);
          digitalWrite(led_c, LOW);
          digitalWrite(led_d, LOW);
          digitalWrite(led_e, LOW);
          hasEnemy = false;
          deathAnimation(enemy);
        }
        else {
          incomingFire();
        }
        break;
      case 'c':
        // statements
        if (enemy == 3) {
          digitalWrite(led_a, LOW);
          digitalWrite(led_b, LOW);
          digitalWrite(led_c, LOW);
          digitalWrite(led_d, LOW);
          digitalWrite(led_e, LOW);
          hasEnemy = false;
          deathAnimation(enemy);
        }
        else {
          incomingFire();
        }
        break;
      case 'd':
        // statements
        if (enemy == 4) {
          digitalWrite(led_a, LOW);
          digitalWrite(led_b, LOW);
          digitalWrite(led_c, LOW);
          digitalWrite(led_d, LOW);
          digitalWrite(led_e, LOW);
          hasEnemy = false;
          deathAnimation(enemy);
        }
        else {
          incomingFire();
        }
        break;
      case 'e':
        // statements
        if (enemy == 5) {
          digitalWrite(led_a, LOW);
          digitalWrite(led_b, LOW);
          digitalWrite(led_c, LOW);
          digitalWrite(led_d, LOW);
          digitalWrite(led_e, LOW);
          hasEnemy = false;
          deathAnimation(enemy);
        }
        else {
          incomingFire();
        }
        break;
      default:
        // statements
//        digitalWrite(led_a, LOW);
//        digitalWrite(led_b, LOW);
//        digitalWrite(led_c, LOW);
//        digitalWrite(led_d, LOW);
//        digitalWrite(led_e, LOW);
        break;
    }
    
  }
}

int generateEnemy() {

    enemy = random(1, 6);

  switch (enemy) {
      case 1:
        // statements
        digitalWrite(led_a, HIGH);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, LOW);
        hasEnemy = true;
        return 1;
        break;
      case 2:
        // statements
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, HIGH);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, LOW);
        hasEnemy = true;
        return 2;
        break;
      case 3:
        // statements
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, HIGH);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, LOW);
        hasEnemy = true;
        return 3;
        break;
      case 4:
        // statements
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, HIGH);
        digitalWrite(led_e, LOW);
        hasEnemy = true;
        return 4;
        break;
      case 5:
        // statements
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, HIGH);
        hasEnemy = true;
        return 5;
        break;
     default:
       break;
  }

}

void deathAnimation(int enemy) {
  delay(100);
  digitalWrite(enemyArray[enemy-1], HIGH);
  delay(100);
  digitalWrite(enemyArray[enemy-1], LOW);
  score += 1;
}

void incomingFire() {
        digitalWrite(s_1, HIGH);
        delay(180);
        digitalWrite(s_1, LOW);
        delay(180);
         digitalWrite(s_2, HIGH);
        delay(180);
        digitalWrite(s_2, LOW);
        delay(180);
         digitalWrite(s_3, HIGH);
        delay(180);
        digitalWrite(s_3, LOW);
        delay(180);
         digitalWrite(s_4, HIGH);
        delay(180);
        digitalWrite(s_4, LOW);
        delay(180);
        char block = Serial.read();
        if (block == 'g') {
         
        }
        else{loseLife();}
}

void initializeLives() {
        delay(500);
        digitalWrite(life_1, HIGH);
        delay(500);
        digitalWrite(life_2, HIGH);
        delay(500);
        digitalWrite(life_3, HIGH);
}

void loseLife(){
    lives -= 1;
      if(lives == 2){
        digitalWrite(life_3, LOW);
        delay(300);
         digitalWrite(life_3, HIGH);  
        delay(250);
        digitalWrite(life_3, LOW);
        delay(300);
         digitalWrite(life_3, HIGH);
        delay(250);
        digitalWrite(life_3, LOW);
        delay(300);
         digitalWrite(life_3, HIGH);
        delay(250);
         digitalWrite(life_3, LOW);
      }
      if(lives == 1){
        digitalWrite(life_2, LOW);
        delay(300);
         digitalWrite(life_2, HIGH);
        delay(250);
        digitalWrite(life_2, LOW);
        delay(300);
         digitalWrite(life_2, HIGH);
        delay(250);
        digitalWrite(life_2, LOW);
        delay(300);
         digitalWrite(life_2, HIGH);
        delay(250);
         digitalWrite(life_2, LOW);
      }
      if(lives == 0){
        digitalWrite(life_1, LOW);
        delay(300);
         digitalWrite(life_1, HIGH);
        delay(250);
        digitalWrite(life_1, LOW);
        delay(300);
         digitalWrite(life_1, HIGH);
        delay(250);
        digitalWrite(life_1, LOW);
        delay(300);
         digitalWrite(life_1, HIGH);
        delay(250);
         digitalWrite(life_1, LOW);
         delay(500);
         digitalWrite(led_a, HIGH);
        digitalWrite(led_b, HIGH);
        digitalWrite(led_c, HIGH);
        digitalWrite(led_d, HIGH);
        digitalWrite(led_e, HIGH);
        digitalWrite(s_1, HIGH);
        digitalWrite(s_2, HIGH);
        digitalWrite(s_3, HIGH);
        digitalWrite(s_4, HIGH);
        digitalWrite(life_1, HIGH);
        digitalWrite(life_2, HIGH);
        digitalWrite(life_3, HIGH);
        delay(500);
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, LOW);
        digitalWrite(s_1, LOW);
        digitalWrite(s_2, LOW);
        digitalWrite(s_3, LOW);
        digitalWrite(s_4, LOW);
        digitalWrite(life_1, LOW);
        digitalWrite(life_2, LOW);
        digitalWrite(life_3, LOW);
        delay(500);
         digitalWrite(led_a, HIGH);
        digitalWrite(led_b, HIGH);
        digitalWrite(led_c, HIGH);
        digitalWrite(led_d, HIGH);
        digitalWrite(led_e, HIGH);
        digitalWrite(s_1, HIGH);
        digitalWrite(s_2, HIGH);
        digitalWrite(s_3, HIGH);
        digitalWrite(s_4, HIGH);
        digitalWrite(life_1, HIGH);
        digitalWrite(life_2, HIGH);
        digitalWrite(life_3, HIGH);
        delay(500);
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
        digitalWrite(led_c, LOW);
        digitalWrite(led_d, LOW);
        digitalWrite(led_e, LOW);
        digitalWrite(s_1, LOW);
        digitalWrite(s_2, LOW);
        digitalWrite(s_3, LOW);
        digitalWrite(s_4, LOW);
        digitalWrite(life_1, LOW);
        digitalWrite(life_2, LOW);
        digitalWrite(life_3, LOW);
        delay(500);
         //gameover case
         showScore(score);
      }
}
void showScore(int score){
  delay(1000);
  for(int i= 1; i<=score; i++){
    digitalWrite(s_4, HIGH);
    delay(400);
    digitalWrite(s_4, LOW);
    delay(400);
    }
  }



  
