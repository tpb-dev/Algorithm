/// sのkmpテーブルを構築する Rは長さs.size()以上の配列へのポインタ
void kmp(string s, int R[]) {
    R[0] = -1;
    int j = -1;
    for (int i = 0; i < s.size() ; i++) {
        while (j >= 0 && s[i] != s[j]) j = R[j];
        j++;
        R[i+1] = j;
    }
}
