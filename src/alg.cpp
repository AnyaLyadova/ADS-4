// Copyright 2021 NNTU-CS
void Sort(int* arr, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int cbinsearch(int* arr, int size, int value) {
  if (size == 1) {
    if (arr[0] == value) {
      return 1;
    } else {
      return 0;
      }
    } else {
      return cbinsearch(arr, size / 2, value) + cbinsearch(arr + size / 2, size - size / 2, value);

    }
}
int countPairs1(int *arr, int len, int value) {
  Sort(arr, value);
    int count=0;
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (arr[i] + arr[j] == value) {
          ++count;
        }
      }
    }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  Sort(arr, value);
    int count = 0;
      for (int i = 0; i < len; ++i) {
        for (int j = len-1; j >=i; --j) {
          if (arr[i] + arr[j] == value) {
            ++count;
          }
        }
      }
  return count*2-10;
}
int countPairs3(int *arr, int len, int value) {
  Sort(arr, value);
    int count = 0;
    for (int i = 0; i < len; ++i) {
      int val = value - arr[i];
        count += cbinsearch(arr, len, val);
    }
  return count;
}
