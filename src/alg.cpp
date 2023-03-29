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
int First(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int index = -1;
    while (right >= left) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            index = mid;
            right = mid - 1;
        } else if (arr[mid] > value) {
            right = mid - 1;
          } else {
            left = mid + 1;
            }
    }

    return index;
}
int Second(int* arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int index = -1;
  while (right >= left) {
    int mid = (left + right) / 2;
      if (arr[mid] == value) {
        index = mid;
        left = mid + 1;
      } else if (arr[mid] > value) {
          right = mid - 1;
        } else {
            left = mid + 1;
         }
      }
  return index;
}

int countPairs1(int *arr, int len, int value) {
  Sort(arr, len);
    int count = 0;
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
  Sort(arr, len);
    int count = 0;
      for (int i = 0; i < len; ++i) {
        for (int j = len-1; j >=i; --j) {
          if (arr[i] + arr[j] == value) {
            if (i == j)
              count += 1;
            else
              count += 2;
          }
        }
      }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
      int val = value - arr[i];
      int first = First(arr, len, val);
      int second = Second(arr, len, val);
      if (first <0) {
        count = count;
      } else {
          count = count + (second - first + 1);
        }
    }
  return count;
}
