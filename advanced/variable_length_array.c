// tis-analyzer -val -val-profile interpreter variable_length_array.c

int main() {
    int size = 42;
    short v[size];
    int sizeof_v = sizeof v;
    for (int i = 0; i < size; ++i)
      v[i] = i;
}
