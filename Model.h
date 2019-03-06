#ifndef CLASS_MODEL
#define CLASS_MODEL

//#include "mpi.h"

class Model {
	public:
		Model(int argc, char* argv[]);
//        ~Model();

        void PrintParameters(); //done

        bool IsValid(); //done

        void PrintHelp(); //done

        // Getters
		bool   IsVerbose() const { return verbose; }
        bool   IsHelp()    const { return help; }
        double GetX0()     const { return x0; }
        double GetY0()     const { return y0; }
        double GetLx()     const { return Lx; }
        double GetLy()     const { return Ly; }
        double GetT()      const { return T; }
        int    GetNx()     const { return Nx; }
        int    GetNy()     const { return Ny; }
        int    GetNt()     const { return Nt; }
        double GetDx()     const { return dx; }
        double GetDy()     const { return dy; }
        double GetDt()     const { return dt; }
        double GetAx()     const { return ax; }
        double GetAy()     const { return ay; }
        double GetB()      const { return b; }
        double GetC()      const { return c; }

        // Add any other getters here...

	private:
        void ParseParameters(vector <string> argv); //done
        void ValidateParameters(vector <string> argv); //done

	    bool verbose;
        bool help;
        bool valid;
        string fname;

	    // Numerics
	    double x0;
	    double y0;
	    double Lx;
	    double Ly;
	    double T =1;
	    int    Nx = 20;
	    int    Ny = 20;
	    int    Nt =30;
	    double dx;
	    double dy;
	    double dt;

	    // Physics
	    double ax;
	    double ay;
	    double b;
	    double c;

        // Add any additional parameters here...
};

Model::Model(int argc, char* argv[]) {
    vector <string> parameters_physics; //?
    for(int i=1; i < argc; ++i ) {
        string arg = argv[i];
		if (arg == "-h" || arg == "--help"){
			help = true; verbose = false;
		}
		else if (arg == "-v" || arg == "--verbose"){
			verbose = true; help = false;
			parameters_physics.push_back(arg);
		}
		else {
			verbose = false; help = false;
            parameters_physics.push_back(arg);
		}
    }
	
    if (help==false) {
        ParseParameters(parameters_physics);
        Lx = 10;
        Ly = 10;
        T = 0.0;
		ValidateParameters(parameters_physics);
        if (verbose==true) {
            PrintParameters();
        }
    }
};

//
//
//         ***BELOW ARE ALL THE FUNCTIONS FROM MODEL.H***
//
//

void Model::ParseParameters(vector <string> argv) {
        ax = stod(argv[0]);
        ay = stod(argv[1]);
        b = stod(argv[2]);
        c = stod(argv[3]);
		if (verbose == true){
			cout << "Parameters passed: " << ax << " " << ay << " " << b << " " << c <<endl;
		}
    };


void Model::PrintHelp() {
    if(help==true){
		cout << "THIS WILL BE A HELP SCREEN"<< endl;
		}
};

void Model::PrintParameters(){
	cout << "If verbose is on, print parameters here." << endl;
}

void Model::ValidateParameters(vector <string> argv){
	int argc = argv.size();
    if (argc != 4) {
		valid = false;
		IsValid();
        cout << "Error: Incorrect number of arguments (" << argc << " instead of 4)" << endl;
		help = true; PrintHelp();
        
		}
	else if (c<0) {
		valid = false;
		IsValid();
		cout << "Error: 'C' should be a positive value, or zero." << endl;
		help = true; PrintHelp();
	}
	else {
		valid = true;
		IsValid();
	}
	
}

bool Model::IsValid(){
	if (valid==true && verbose==true){
		cout << "Parameters are valid." << endl;
	}
	else if (valid = false){
		cout << "Parameters are invalid." << endl;
		}
}

#endif