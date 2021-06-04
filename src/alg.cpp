// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int k = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if ((arr[i] + arr[j]) == value) {
k++;
}
}
}
return k;
}

}

int countPairs2(int *arr, int len, int value) {
int k = 0, n = len - 1;
while (arr[0] + arr[n] > value){
n--;
}
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n + 1; j++) {
if (arr[i] + arr[j] == value) {
k++;
}
}
}
return k ;

}

int countPairs3(int *arr, int len, int value) {
int sum = 0;
for (int m = 0; m < len - 1; m++) {
int i = m + 1;
int j = len - 1;
int target = -1;
while (i <= j) {
if (arr[i + (j - i + 1) / 2] + arr[m] == value) {
target = i + (j - i + 1) / 2;
break;
}
else {
if (arr[i + (j - i + 1) / 2] + arr[m] < value)
i = i + (j - i + 1) / 2 + 1;
else
j = i + (j - i + 1) / 2 - 1;
}
}
bool error = true;
if (target != -1) {
for (int z = m + 1; z < len; z++) {
if (arr[target] == arr[z]) {
sum++;
error = false;
}
else if (!error) {
break;
}
}
}
}
return sum;
}
