#ifndef PROGRAM_4_11_H
#define PROGRAM_4_11_H

// program.4.11 - Реализация АТД отношений эквивалентности

class UF {
   public:
    explicit UF(int n) : id_{new int[n]}, sz_{new int[n]} {
        for (int i = 0; i < n; ++i) {
            id_[i] = i;
            sz_[i] = 1;
        }
    }

    ~UF() {
        delete[] id_;
        delete[] sz_;
    }

    int Find(int p, int q) { return Find(p) == Find(q); }

    void Unite(int p, int q) {
        int i = Find(p);
        int j = Find(q);
        if (i == j) return;
        if (sz_[i] < sz_[j]) {
            id_[i] = j;
            sz_[j] += sz_[i];
        } else {
            id_[j] = i;
            sz_[i] += sz_[j];
        }
    }

   private:
    int Find(int x) {
        while (x != id_[x]) x = id_[x];
        return x;
    }

   private:
    int* id_;
    int* sz_;
};

#endif /* PROGRAM_4_11_H */
