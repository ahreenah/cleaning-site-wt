g++ -std=c++14 -o hello *.cpp -lwthttp -lwt
./hello --docroot . --http-address 0.0.0.0 --http-port 9090
