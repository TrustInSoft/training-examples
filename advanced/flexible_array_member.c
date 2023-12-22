// tis-analyzer -val -val-profile interpreter flexible_array_member.c
//
// TrustInSoft Analyzer supports the C99 flexible array members syntax and the
// zero-length array GNU extension, by checking accesses against the base only.
// The C90 idiom does not allow accesses past index 0.

# include <stdlib.h>

struct vector_fam {
    int size;
    // int tab[1]; // C90-era idiom
    // int tab[0]; // zero-length array (GNU extension)
    int tab[]; // flexible array member (C99)
};

struct vector_fam *allocate_vector(int size) {
    struct vector_fam *v = malloc(sizeof (*v) + size * sizeof (int));
    v->size = size;
    return v;
}

int main() {
    struct vector_fam *v = allocate_vector(42);
    v->tab[0] = -1;
    v->tab[2] = 17; // alarm with C90 idiom
    v->tab[42] = 0; // UB in all cases
}
