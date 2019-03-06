#ifndef BURGERS_H
#define BURGERS_H

class burgers
{
public:
    burgers(Model* m);
    //   ~burgers();
    
        // Declaring functions
    void Initial_velocity();
    void Integrate_velocity();

private:

    // Numerics
    double x0;
    double y0;
    double Lx;
    double Ly;
    double T;
    int  Nx;
    int  Ny;
    int Nt;
    double dx;
    double dy;
    double dt;

    // Physics
    double ax;
    double ay;
    double b;
    double c;
    
    // 
    
};

burgers::burgers(Model* m)
{
        
    ax = m->GetAx();
    ay = m->GetAy();
    b = m->GetB();
    c = m->GetC();
    Nt = m->GetNt();
    Ny = m->GetNy();
    Nx = m->GetNx();
    dx = m->GetDx();
    dy = m->GetDy();
    dt = m->GetDt();
    Lx = m->GetLx();
    Ly = m->GetLy();
    T = m->GetT();
    x0 = m->GetX0(); 
    y0 = m->GetY0();

    }


void burgers::Initial_velocity()
{
    
    // Initialisation
    double L = Lx;
    double uArray[Nx][Ny];
    double unArray[Nx][Ny];
    double vArray[Nx][Ny];
    double vnArray[Nx][Ny];
    double rhsxArray[Nx][Ny];
    double rhsyArray[Nx][Ny];
    double xArray[Nx][Ny];

    // double dx = L / (Nx -1);
    // double dy = L / (Ny -1);
    // double dt = T / Nt;

    double x[Nx];
    double y[Ny];
    double u[Nx][Ny];
    double v[Nx][Ny];

    x[0] = -L / 2;
    y[0] = -L / 2;

    for(int temp = 1; x[Nx] > 0; temp++) {
        x[temp] = x[temp - 1] + dx;
    }

    for(int temp = 1; y[Ny] > 0; temp++) {
        y[temp] = y[temp - 1] + dy;
    }

    // Initial Conditions

    for(int i = 0; i < Nx; i++) {
        for(int j = 0; j < Ny; j++) {
            double r = pow(pow(x[i], 2) + pow(y[j], 2), 2);
            if(r <= 1) {
                u[i][j] = 2 * pow(1 - r, 4) * (4 * r + 1);
                v[i][j] = u[i][j];
            } else {
                u[i][j] = 0;
                v[i][j] = 0;
            }
        }
    }

    // Boundary Conditions
    for(int temp = 0; temp < Ny; temp++) {
        u[0][temp] = 0.0;
        u[Nx][temp] = 0.0;
        v[0][temp] = 0;
        v[Nx][temp] = 0;
    }

    for(int temp = 0; temp < Nx; temp++) {
        u[temp][1] = 0.0;
        u[temp][Ny] = 0.0;
        v[temp][1] = 0;
        v[temp][Ny] = 0;
    }


//    for(int temp = 0; temp < Nx; temp++) {
//        for(int temp2=0; temp2 < Ny; temp2++){
//            cout << u[temp][temp2] << endl;
//        }
//    }

}


// 
// SECOND FUNCTION
//

void burgers::Integrate_velocity()
{


//    double un[Nx][Ny];
//    double vn[Nx][Ny];
//    
//    // Integration
//    int mArray[Nx - 2];
//    for(int m = 1; m < Nx - 1; m++) {
//        mArray[m] = m;
//    }
//
//    int nArray[Ny - 2];
//    for(int n = 1; n < Ny - 1; n++) {
//        nArray[n] = n;
//    }
//
//    for(int it = 0; it < Nt + 1; it++) {
//
//        for(int tempx = 0; tempx++; tempx < Nx) {
//            for(int tempy = 0; tempy++; tempy < Ny) {
//                un[tempx][tempy] = u[tempx][tempy];
//                vn[tempx][tempy] = v[tempx][tempy];
//            }
//        }
//
//        for(int i = 1; i < Nx - 1; i++) {
//
//            for(int j = 1; j < Ny - 1; j++) {
//
//                u[i][j] = un[i][j] - (dt * (un[i][j] - un[i - 1][j]) * (ax + b * un[i][j]) / dx) -
//                    (dt * (un[i][j] - un[i][j - 1]) * (ay + b * vn[i][j]) / dy) +
//                    (c * dt * (un[i + 1][j] - 2 * un[i][j] + un[i - 1][j]) / (dx * dx)) +
//                    (c * dt * (un[i][j - 1] - 2 * un[i][j] + un[i][j + 1]) / (dy * dy));
//
//                v[i][j] = vn[i][j] - (dt * (vn[i][j] - vn[i - 1][j]) * (ax + b * un[i][j]) / dx) -
//                    (dt * (vn[i][j] - vn[i][j - 1]) * (ay + b * vn[i][j]) / dy) +
//                    (c * dt * (vn[i + 1][j] - 2 * vn[i][j] + vn[i - 1][j]) / (dx * dx)) +
//                    (c * dt * (vn[i][j - 1] - 2 * vn[i][j] + vn[i][j + 1]) / (dy * dy));
//            }
//        }
//
//        for(int temp = 0; temp++; temp < Ny) {
//            u[0][temp] = 0.0;
//            u[Nx][temp] = 0.0;
//            v[0][temp] = 0;
//            v[Nx][temp] = 0;
//        }
//
//        for(int temp = 0; temp++; temp < Nx) {
//            u[temp][1] = 0.0;
//            u[temp][Ny] = 0.0;
//            v[temp][1] = 0;
//            v[temp][Ny] = 0;
//        }
//    }
    
}

#endif // BURGERS_H