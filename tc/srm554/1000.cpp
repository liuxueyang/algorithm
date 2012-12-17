#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXH = 50;
long long int dp[4][4][4][4][MAXH];
//unsigned int dp[4][4][4][4][MAXH];
const  long long int MOD = 1234567891;

class TheBrickTowerHardDivTwo {
    public:
        int find(int C, int K, int H) {
            memset(dp,0,sizeof(dp));

            for(int a=0; a<C; a++){
                for(int b=0; b<C; b++){
                    for(int c=0; c<C; c++){
                        for(int d=0; d<C; d++){
                            int cnt = 0;
                            if(a==b){
                                cnt++;
                            }
                            if(a==c){
                                cnt++;
                            }
                            if(b==d){
                                cnt++;
                            }
                            if(c==d){
                                cnt++;
                            }
                            if(cnt<=K){
                                //cout<<"a b c d "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                                dp[a][b][c][d][0] = 1;
                            }

                        }
                    }
                }
            }

            for(int height=1; height<H; height++){
                for(int a=0; a<C; a++){
                    for(int b=0; b<C; b++){
                        for(int c=0; c<C; c++){
                            for(int d=0; d<C; d++){
                                int cnt = 0;
                                if(a==b){
                                    cnt++;
                                }
                                if(a==c){
                                    cnt++;
                                }
                                if(b==d){
                                    cnt++;
                                }
                                if(c==d){
                                    cnt++;
                                }

                                for(int e=0; e<C; e++){
                                    for(int f=0; f<C; f++){
                                        for(int g=0; g<C; g++){
                                            for(int h=0; h<C; h++){
                                                int tmp_cnt = cnt;
                                                if(e==f)tmp_cnt++;
                                                if(e==g)tmp_cnt++;
                                                if(f==h)tmp_cnt++;
                                                if(g==h)tmp_cnt++;

                                                if(e==a)tmp_cnt++;
                                                if(f==b)tmp_cnt++;
                                                if(g==c)tmp_cnt++;
                                                if(h==d)tmp_cnt++;


                                                if(tmp_cnt<=K){
                                                    dp[e][f][g][h][height] += dp[a][b][c][d][height-1];
                                                    dp[e][f][g][h][height] %= MOD;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            long long int ans = 0;

            for(int height=0; height<=H-1; height++){
                for(int a=0; a<C; a++){
                    for(int b=0; b<C; b++){
                        for(int c=0; c<C; c++){
                            for(int d=0; d<C; d++){
                                ans+=dp[a][b][c][d][height];
                                ans%=MOD;
                            }
                        }
                    }
                }
            }
            int final_ans = ans%MOD;
            return final_ans;
        }

};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
    cout << "]" << endl;
    TheBrickTowerHardDivTwo *obj;
    int answer;
    obj = new TheBrickTowerHardDivTwo();
    clock_t startTime = clock();
    answer = obj->find(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    int p2;
    int p3;

    {
        // ----- test 0 -----
        p0 = 2;
        p1 = 0;
        p2 = 2;
        p3 = 4;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        p0 = 1;
        p1 = 7;
        p2 = 19;
        p3 = 1;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 2;
        p1 = 3;
        p2 = 1;
        p3 = 14;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 4;
        p1 = 7;
        p2 = 47;
        p3 = 1008981254;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING