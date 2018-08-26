class Solution {
  public int numSpecialEquivGroups(String[] A) {
    HashSet<MyString> set = new HashSet<MyString>();
    for(String s : A) {
      MyString ms = new MyString(s);
      set.add(ms);
    }
    return set.size();
  }
}

class MyString {
  String even="", odd="";
  public MyString(String s) {
    for(int i=0; i < s.length(); i++) {
      if(i % 2 == 0) {
        even += s.charAt(i);
      }
      else odd += s.charAt(i);
    }
    char[] ar=even.toCharArray();
    char[] br=odd.toCharArray();
    Arrays.sort(ar);
    Arrays.sort(br);
    even = String.valueOf(ar);
    odd = String.valueOf(br);
  }
  public int hashCode() {
    return new Integer(even).hashCode();
  }
  public boolean equals(Object st) {
    MyString ms = (MyString)st;
    return (even.equals(ms.even)) && (odd.equals(ms.odd));
  }
}
