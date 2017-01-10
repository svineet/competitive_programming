#include <bits/stdc++.h>
using namespace std;

complex<float> rotate_point(complex<float> point, complex<float> origin) {
    complex<float> inter = point-origin;
    complex<float> result = inter*complex<float>(0, 1);
    return (result+origin);
}

bool is_square(complex<float> A, complex<float> B,
               complex<float> C, complex<float> D) {
    if (A==B || A==C || A==D || B==C || B==D
             || C==D)
        return false;

    complex<float> center = (A+B+C+D);
    center = complex<float>(center.real()/4.0, center.imag()/4.0);
    complex<float> adist = A-center;
    complex<float> adash = complex<float>(-float(adist.imag()), adist.real());

    complex<float> one = center-adist,
                   two = center+adash,
                   three = center-adash;

    if ((B == one && C == two && D == three) ||
        (B == one && C == three && D == two) ||
        (B == two && C == one && D == three) ||
        (B == two && C == three && D == one) ||
        (B == three && C == one && D == two) ||
        (B == three && C == two && D == one)) {
        return true;
    }

    return false;
}

int main() {
    int n; cin >> n;
    while (n--) {
        vector< complex<float> > points;
        vector< complex<float> > rotations[4];
        vector< complex<float> > origins;
        for (int i=0; i<4; i++) {
            int x, y; int ox, oy;
            cin >> x >> y >> ox >> oy;
            points.push_back(complex<float>(x, y));
            rotations[i].push_back(complex<float>(x, y));
            // first rotation is the point itself
            origins.push_back(complex<float>(ox, oy));
        }

        for (int i=0; i<4; i++) {
            for (int j=1; j<4; j++) {
                // Add the three rotations
                rotations[i].push_back(rotate_point(rotations[i][j-1], origins[i]));
            }
        }

        int result = 1e8;
        bool got = false;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                for (int k=0; k<4; k++) {
                    for (int w=0; w<4; w++) {
                        if (is_square(rotations[0][i],
                                      rotations[1][j],
                                      rotations[2][k],
                                      rotations[3][w])) {
                            result = min(result, i+j+w+k);
                            got = true;
                        }
                    }
                }
            }
        }

        if (!got)
            cout << -1 << endl;
        else
            cout << result << endl;
    }

    return 0;
}
