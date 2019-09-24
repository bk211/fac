int suite (int n) {
  int a;
  a = n >> 1;
  if (n & 0x01)
	return 3 * (a + 1);
  return a;

}
