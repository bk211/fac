int very_brutal(int argc, char const *argv[]) {
    auto start = steady_clock::now();

    unsigned long long int _1milliads= 1000000000;
    auto million = 1000000;
    if( argc == 3){
    long max;
    int nb_thread=3;
    istringstream s1(argv[1]);
    s1 >> max;
    istringstream s2(argv[2]);
    s2 >> nb_thread;
    //cout <<"max is "<< max << '\n';
    //cout << "nb_thread"<<nb_thread << '\n';


    //cout << vec.max_size() << '\n';
    vec.assign(million, true);
    //cout <<"current_vec capacity"<< vec.capacity() << '\n';
    vec[0] = false;
    vec[1] = false;
//    int* task_tab = new int[nb_thread];

    brute_force(vec, 2,million);

    }
    else{
    cout << "Usage:./executable N X" << '\n';
    return 0;
    }


    //TODO  export output to file
    write_file(vec, 0, million);

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Time used:" << duration<double, milli> (diff).count()<<"ms"<< '\n';
    return 0;
}
