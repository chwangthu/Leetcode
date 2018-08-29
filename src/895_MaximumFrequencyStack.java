class FreqStack {
  Map<Integer, Integer> freq = new HashMap();
  Map<Integer, Stack<Integer>> freqStack = new HashMap();
  int maxFreq = 0;
  public FreqStack() {}
  public void push(int x) {
    int f = freq.getOrDefault(x, 0) + 1;
    freq.put(x, f);
    if(maxFreq < f) {
      maxFreq = f;
    }
    freqStack.computeIfAbsent(f, z -> new Stack()).push(x);
  }
  public int pop() {
    int x = freqStack.get(maxFreq).pop();
    freq.put(x, freq.get(x) - 1);
    if(freqStack.get(maxFreq).size == 0) {
      maxFreq--;
    }
    return x;
  }
}
