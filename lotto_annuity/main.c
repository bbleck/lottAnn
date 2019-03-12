//
//  main.c
//  lottAnn
//
//  A calculation for estimated annuity payments from
//  a jackpot win. Period is 30 years.
//  Created by Brian on 3/12/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
  
  double total = 450.0;//the total jackpot
  double x = total;
  double first = x;//the amount of the first payment
  double sum = 0;//the total amount paid
  double yearlyIncrease = 1.05;//annuities pay 5% more each year
  double granularity = 0.01;//adjustment for accuracy of sum = total at the end
  int i = 0;
  int term = 30;//number of years the annuity pays out over

  while(1){
    x = first;
    sum = first;
    for (i=1; i<term; i++) {
      x *= yearlyIncrease;
      sum += x;
    }
    if((total-sum)>=0){
      break;
    }else{
      first -= granularity;
    }
  }
  sum = 0;//reset the sum
  for (i=1; i<=term; i++) {
    sum += first;
    printf("payment %d = $%.2f Million, sum = $%.2f Million\n", i, first, sum);
    first *= yearlyIncrease;
  }
  
  return 0;
}
