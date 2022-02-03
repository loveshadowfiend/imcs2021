uint64_t check(uint64_t m, uint64_t n, uint64_t p, uint64_t c);

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    uint64_t n, p, c;
    fscanf(input, "%llu %llu %llu", &n, &p, &c);
    uint64_t i = 0, j = c;
    while (i + 1 < j) {
        uint64_t m = i + (j - i) / 2;
        if (check(m, n, p, c) == 0) {
            i = m;
        } else {
            j = m;
        }
    }
    fprintf(output, "%llu", j);
}

uint64_t check(uint64_t m, uint64_t n, uint64_t p, uint64_t c) {
    uint64_t origin = c;
    for (uint64_t i = 0; i < n * 12; i++) {
        if (c <= m)
            return 1;
        c -= m;
        c += (c * p / 100) + (((c * p) % 100) != 0);
        if (c >= origin) 
            return 0;
    }
    if (c == 0)
        return 1;
    return 0;
}
