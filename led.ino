//int ControlPin = 10;
//int code[16][4] = { {0, 0, 0, 0},
//  {0, 0, 0, 1},
//  {0, 0, 1, 0},
//  {0, 0, 1, 1},
//  {0, 1, 0, 0},
//  {0, 1, 0, 1},
//  {0, 1, 1, 0},
//  {0, 1, 1, 1},
//  {1, 0, 0, 0},
//  {1, 0, 0, 1},
//  {1, 0, 1, 0},
//  {1, 0, 1, 1},
//  {1, 1, 0, 0},
//  {1, 1, 0, 1},
//  {1, 1, 1, 0},
//  {1, 1, 1, 1}
//};
//
//int p[15] = {1, 0, 1, 0, 1, 0, 0, 0, 0, 0};
//float start = millis();
//float t = 1000.0 / 15.16;
//
//void CreateMessage(int data = 0)
//{
//  p[6] = code[data][0];
//  p[7] = code[data][1];
//  p[8] = code[data][2];
//  p[9] = code[data][3];
//}
//
//void setup()
//{
//  CreateMessage(5);
//  pinMode(ControlPin, OUTPUT);
//  Serial.begin(19200);
//}
//
//void SendOld(int s[], float rate)
//{
//  for (int i = 0; i < 2; i++)
//  {
//    digitalWrite(ControlPin, s[i]);
//    delay(1000 / rate);
//    //Serial.println(1000/(millis()-start));
//    start = millis();
//  }
//}
//
//void Send()
//{
//  int i = 0;
//  while (i < 10)
//  {
//    while ((millis() - start) < t);
//    Serial.println(1000 / (millis() - start));
//    start = millis();
//    digitalWrite(ControlPin, p[i]);
//    Serial.println(p[i]);
//    i++;
//  }
//}
//int k = 3;
//void loop()
//{
//  for (int da = 1; da < 11; da++)
//  {
//    CreateMessage(da);
//    Send();
//  }
//}

int ControlPin = 2;
int code[16][4] = { {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 1},
  {1, 0, 1, 0},
  {1, 0, 1, 1},
  {1, 1, 0, 0},
  {1, 1, 0, 1},
  {1, 1, 1, 0},
  {1, 1, 1, 1}
};

int p[15] = {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float start = millis();
float t = 1000.0 / 15.16;

void CreateMessage(int data = 0)
{
  p[6] = code[data][0];
  p[7] = code[data][1];
  p[8] = code[data][2];
  p[9] = code[data][3];
}

void setup()
{
  CreateMessage(5);
  pinMode(ControlPin, OUTPUT);
  Serial.begin(9600);
}

void SendOld(int s[], float rate)
{
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(ControlPin, s[i]);
    delay(1000 / rate);
    //Serial.println(1000/(millis()-start));
    start = millis();
  }
}

void Send()
{
  int i = 0;
  while (i < 15)
  {
    while ((millis() - start) < t);
    //Serial.println(1000 / (millis() - start));
    start = millis();
    digitalWrite(ControlPin, p[i]);
    //Serial.println(p[i]);
    i++;
  }
}
int k = 3;
void loop()
{
  CreateMessage(5);
  Send();
  CreateMessage(6);
  Send();
}


/*  `
  Rough:
  If rate = 15,
              --> 15 bits in 1 second
              --> 15 bits in 1000 microseconds
              --> 1 bit in 1000/15 microseconds
              --> 1 bit in 1000/15 microseconds
  If rate = r,
              --> 1 bit in 1000/r microseconds
*/
