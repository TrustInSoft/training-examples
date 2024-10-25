// tis gui variable_length_array

void f(int size) {
    short v[size];
    int sizeof_v = sizeof v;
    for (int i = 0; i < size; ++i)
      v[i] = i;
}

int main() {
    f(42);
}
