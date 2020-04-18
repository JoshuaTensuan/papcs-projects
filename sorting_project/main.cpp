#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h> 
#include <sstream>
#include <random>

int partition(std::vector<int> &vec, int begin, int end) {
    int pivot = vec.at(end);
    int i = begin - 1;
    for(int j = begin; j < end; j++) {
        if(vec.at(j) < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[end]);
    return i+1;
}

void quicksort_helper(std::vector<int> &vec, int begin, int end) {
    if(begin < end) {
        int part = partition(vec, begin, end);
        quicksort_helper(vec, begin, part -1);
        quicksort_helper(vec, part+1, end);
    }
}

void quicksort(std::vector<int> &vec) {
    quicksort_helper(vec, 0, vec.size() - 1);
}

void countingsort(std::vector<int> &vec, int base, int log) {
    std::vector<int> ret(vec.size());
    int aux[base];
    for(int i = 0; i < base; i++) {
        aux[i] = 0;
    }
    for(std::vector<int>::iterator x = vec.begin(); x != vec.end(); x++) {
        aux[(*x/(int) (pow(base, log))) % base] += 1;
    }
    for(int i = 1; i < base; i++) {
        aux[i] += aux[i-1];
    }
    for(std::vector<int>::iterator x = vec.end(); x-- != vec.begin(); ) {
        ret.at(aux[(*x/(int) (pow(base, log))) % base] - 1) = *x;
        aux[(*x/(int) (pow(base, log))) % base] -= 1; 
    }
    vec = ret;
}

int getMax(std::vector<int> vec) {
    int temp = INT_MIN;
    for(std::vector<int>::iterator x = vec.begin(); x != vec.end(); x++) {
        if(*x > temp) {
            temp = *x;
        }
    }
    return temp;
}

int intlog(double base, double x) {
    return (int)floor(log(x) / log(base));
}

void radixsort_helper(std::vector<int> &vec, int bins, int max) {
    int log = intlog((double) bins, (double) max);
    for(int i = 0; i <= intlog((double) bins, (double) max); i++) {
        countingsort(vec, bins, i);
    }
}

void radixsort(std::vector<int> &vec, int bins) {
    radixsort_helper(vec, bins, getMax(vec));
}

void soil_moisture_data(std::vector<int> &vec) { // ideal bin size is about 180
    std::ifstream file("soilmoisture_dataset_conc.csv"); // https://github.com/felixriese/hyperspectral-soilmoisture-dataset
    std::string line = "";
	// Iterate through each line and split the content using delimeter
	while (getline(file, line)) {
        std::stringstream s_stream(line);
        while(s_stream.good()) {
            std::string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            double number = 0;
            std::istringstream iss (line);
            iss >> number;
            int push = (int) ceil(number * pow(10,10));
            vec.push_back(push);
        }
	}
	// Close the File
	file.close();   
}

void baltimore_income_fy2019(std::vector<int> &vec) { // ideal bin size is about 155
    std::ifstream file("baltimore-city-salaries.csv"); // https://data.world/baltimore/6xv6-e66h
    std::string line = "";
	// Iterate through each line and split the content using delimeter
	while (getline(file, line)) {
        int number = 0;
        std::istringstream iss (line);
        iss >> number;
		vec.push_back(number * 100); // this doesnt work for some reason
	}
	// Close the File
	file.close();
}

void sorteddata(std::vector<int> &vec) {
    std::vector<int> v;
    baltimore_income_fy2019(v);
    radixsort(v, 155);
    vec = v;
}

void randomdata(std::vector<int> &vec) {
    srand(124);
    for(int i = 0; i < 50000; i++) {
        int push = rand() % INT_MAX + 1;
        vec.push_back(push);
    }
    
}

void ap_phys_c_em_scores(std::vector<int> &vec) { // from 2019 ap physics c e+m https://apcentral.collegeboard.org/pdf/ap19-chief-reader-report-physics-c-em-set-2.pdf
    srand(123); // ideal bin size is about 9
    int x = 0;
    while (x<50000) {
        double ran = rand()/(double)RAND_MAX;
        int push = 0;
        if(ran < 0.376) {
            push = 5;
        } else if(ran < 0.376 + 0.226) {
            push = 4;
        } else if(ran < 0.376 + 0.226 + 0.127) {
            push = 3;
        } else if(ran < 0.376 + 0.226 + 0.127 + 0.166) {
            push = 2;
        } else {
            push = 1;
        }
        vec.push_back(push);
        // std::cout << push << std::endl;
        x++;
    }
}

void sat_scores(std::vector<int> &vec) { // https://reports.collegeboard.org/pdf/2019-total-group-sat-suite-assessments-annual-report.pdf#page=4&zoom=110,-64,778
    srand(122); // based off normal distribution
    int x = 0; // ideal bin size is about 150
    std::random_device rd;

    std::mt19937 e2(rd());

    std::normal_distribution<> dist(1059, 210);
    while(x<500000) {
        float num = dist(e2);
        if(num <= 400) {
            vec.push_back(400);
        } else if(num >= 1600) {
            vec.push_back(1600);
        } else {
            int push = ceil(num / 10.0) * 10;
            // std::cout << push << std::endl;
            vec.push_back(push);
        }
        x++;
    }

}


int main() {
    srand(123);

    std::vector<int> vec;

    // sorteddata(vec);
    // randomdata(vec);
    // ap_phys_c_em_scores(vec);
    // baltimore_income_fy2019(vec);
    soil_moisture_data(vec);
    // sat_scores(vec);
    // for(int x = 0; x < 4; x++) {
    //     std::cout << a[x];
    // }
    int trials = 10;
    double r_dur = 0;
    bool rsort = true;
    bool qsort = true;
    double q_dur = 0;

    if(rsort) {
        std::cout << "Starting radix sort" << std::endl;
        for(int i = 0; i < trials; i++) {
            std::vector<int> vec_r(vec); 
            auto a_StartTime = std::chrono::system_clock::now(); 
            radixsort(vec_r, 180);
            auto a_EndTime = std::chrono::system_clock::now();
            r_dur += std::chrono::duration_cast<std::chrono::milliseconds>(a_EndTime - a_StartTime).count();
            
        }
    }

    if(qsort) {
        std::cout << "Starting quick sort" << std::endl;
        for(int j = 0; j < trials; j++) {
            std::vector<int> vec_q(vec); 
            auto b_StartTime = std::chrono::system_clock::now();
            quicksort(vec_q);
            auto b_EndTime = std::chrono::system_clock::now();
            q_dur += std::chrono::duration_cast<std::chrono::milliseconds>(b_EndTime - b_StartTime).count();
        }
    }

    if(qsort) {
        std::cout << "quicksort run time: " << q_dur/trials << " ms." << std::endl;
    }
    if(rsort) {
        std::cout << "radixsort run time: " << r_dur/trials << " ms." << std::endl;
    }
}