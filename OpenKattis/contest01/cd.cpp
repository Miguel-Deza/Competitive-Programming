#include<iostream>
#include<set>

bool debug = false;

int main(int argc, char *argv[])
{
    if(argc > 1) debug = true;

    std::ios_base::sync_with_stdio(false);

    int N, M;
    while(std::cin >> N >> M, (N || M)) {
        std::set<int> catalogJack;
        for(int n = 0; n < N; n++) {
            int cd;
            std::cin >> cd;
            catalogJack.insert(cd);
        }
        int common = 0;
        std::set<int>::const_iterator ci = catalogJack.begin();
        for(int m = 0; m < M; m++) {

            int cd;
            std::cin >> cd;

            while(ci != catalogJack.end()) {
                if(*ci < cd) {
                    ci++;
                    continue;
                } else if(*ci == cd) {
                    if(debug) std::cout << "Common cd " << cd << std::endl;
                    common++;
                    ci++;
                    break;
                } else
                    break;
            }
        }
        std::cout << common << std::endl;
    }
    return 0;
}