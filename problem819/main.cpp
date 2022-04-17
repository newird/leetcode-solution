#include <iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string,int> m;
        string res = "";
        int max = 0;
        int cnt = 0;
        string word = "";
        paragraph += ' ';
        const int n = paragraph.size();

        for (int i = 0; i < n; i++) {
            if (ispunct(paragraph[i])||paragraph[i]==' ') {

                transform(word.begin(), word.end(), word.begin(), ::tolower);
//                cout<< word << endl;
                if (word.size() > 0) {
                    if (!ban.count(word)) {
                        m[word]++;
                        if (m[word] > max) {
                            max = m[word];
                            res = word;
                        }
                    }
                    word = "";
                }
            } else {
                word += paragraph[i];
            }
        }
//        cout<<"y"<<m["y"]<<endl;
//        cout<<"u"<<m["u"]<<endl;
        return res;
    }
};

int main() {
    Solution solution;
    string paragraph ="j. t? T. z! R, v, F' x! L; l! W. M; S. y? r! n; O. q; I? h; w. t; y; X? y, p. k! k, h, J, r? w! U! V; j' u; R! z. s. T' k. P? M' I' j! y. P, T! e; X. w? M! Y, X; G; d, X? S' F, K? V, r' v, v, D, w, K! S? Q! N. n. V. v. t? t' x! u. j; m; n! F, V' Y! h; c! V, v, X' X' t? n; N' r; x. W' P? W; p' q, S' X, J; R. x; z; z! G, U; m. P; o. P! Y; I, I' l' J? h; Q; s? U, q, x. J, T! o. z, N, L; u, w! u, S. Y! V; S? y' E! O; p' X, w. p' M, h! R; t? K? Y' z? T? w; u. q' R, q, T. R? I. R! t, X, s? u; z. u, Y, n' U; m; p? g' P? y' v, o? K? R. Q? I! c, X, x. r' u! m' y. t. W; x! K? B. v; m, k; k' x; Z! U! p. U? Q, t, u' E' n? S' w. y; W, x? r. p! Y? q, Y. t, Z' V, S. q; W. Z, z? x! k, I. n; x? z; V? s! g, U; E' m! Z? y' x? V! t, F. Z? Y' S! z, Y' T? x? v? o! l; d; G' L. L, Z? q. w' r? U! E, H. C, Q! O? w! s? w' D. R, Y? u. w, N. Z? h. M? o, B, g, Z! t! l, W? z, o? z, q! O? u, N; o' o? V; S! z; q! q. o, t! q! w! Z? Z? w, F? O' N' U' p? r' J' L; S. M; g' V. i, P, v, v, f; W? L, y! i' z; L? w. v, s! P?";
    vector<string> banned ={"m","q","e","l","c","i","z","j","g","t","w","v","h","p","d","b","a","r","x","n"};
    cout << solution.mostCommonWord(paragraph, banned) << endl;
    return 0;
}
