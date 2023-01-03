void bubblesort_it(int arr[],int n) {
  // Gestisco sottoarray
  for (int k=n-1;k>0;k--) {
    // Porto elemento piu' grande in ultima posizione
    for (int i=0;i<k;i++) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
      }
    }
  }
}

void bubblesort_rec(int arr[], int n) {
  // Caso base
  if (n == 1)
    return;

  // Porto elemento piu' grande in ultima posizione (n-1).
  for (int i=0; i<n-1; i++)
    if (arr[i] > arr[i+1])
      swap(arr[i], arr[i+1]);
  // L'ultimo elemento e' fissato, ricorsione su sub-array rimanente
  // (0, n-2)
  bubblesort_rec(arr, n-1);
}

void bubblesort_rec2(int arr[], int size) {
  bubblesort_rec2(arr, 0, size);
}

void bubblesort_rec2(int arr[], int first, int last) {
  if (first >= last || last > 0)
    // caso base
    return;
  else {
    if(arr[first] > arr[first+1]){
      swap(arr[first], arr[first+1]);
    }
    // Prima ricorsione porta elemento piu' grande in ultima
    // posizione
    bubblesort_rec2(arr, first+1, last);
    // L'ultimo elemento e' fissato, ricorsione su sub-array rimanente
    // (0, n-2)
    bubblesort_rec2(arr, first, last-1);
  }
}
