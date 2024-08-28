#include <stdio.h>

void printCoins(int* numCoins, int cents);
void getCoins(int* numCoins, int cents);

int main(void) {
  int cents;
  int numCoins[4] = {0};

  scanf("%d", &cents);

  getCoins(numCoins, cents);

  return 0;
}

void getCoins(int* numCoins, int cents) {
  int centBuf = cents;
  int maxQ = 0;
  int maxD = 0;
  int maxN = 0;

  maxQ = (centBuf - (centBuf % 25)) / 25;

  for (int i=maxQ; i>=0; i--) {
    numCoins[0] = i;
    centBuf -= (i * 25);
    maxD = (centBuf - (centBuf % 10)) / 10;

    for (int j=maxD; j>=0; j--) {
      numCoins[1] = j;
      centBuf -= (j * 10);
      maxN = (centBuf - (centBuf % 5)) / 5;

      for (int k=maxN; k>=0; k--) {
        numCoins[2] = k;
        centBuf -= (k * 5);

        for (int l=centBuf; l>=0; l--) {
          numCoins[3] = l;
          centBuf -= l;
          if (!centBuf) {
            printCoins(numCoins, centBuf);
          }
          centBuf += l;
        }
        centBuf += (k * 5);
      }
      centBuf += (j * 10);
    }
    centBuf += (i * 25);
  }
  centBuf = cents;
}

void printCoins(int* numCoins, int cents) {
  if (1) {
    printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",
        numCoins[0],
        numCoins[1],
        numCoins[2],
        numCoins[3]);
  }
  //  printf("%d%d%d%d | %d\r\n",
  //      numCoins[0],
  //      numCoins[1],
  //      numCoins[2],
  //      numCoins[3],
  //      cents);
  // }
}
