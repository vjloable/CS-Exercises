public class MinHeap {
  int[] heap;

  private int kSmallest(int k){
    return heap[k];
  }

  private void minHeapify(int[] a, int i){
    if(i*2+2 < a.length){
      int l = 2 * i + 1;
      int r = 2 * i + 2;
      int smaller;
      if (a[r] < a[i]) {
        smaller = r;
      } else {
        smaller = i;
      }
      if (a[l] < a[smaller]) {
        smaller = l;
      }
      if (smaller != i) {
        int temp = a[i];
        a[i] = a[smaller];
        a[smaller] = temp;
        minHeapify(a, smaller);
      }
    }
    heap = a;
  }

  private void buildMinHeap(int[] a) {
    heap = a;
    for (int i = (heap.length / 2)-1; i >= 0; i--) {
      minHeapify(heap, i);
    }
  }

  public static void main(String[] args) {
    int[] a = {150, 80, 40, 30, 10, 70, 110, 100, 20, 90, 60, 50, 120, 140, 130};
    MinHeap minheap = new MinHeap();
    minheap.buildMinHeap(a);    
    System.out.printf("\nk-th smallest: %d", minheap.kSmallest(5));
  }

}
