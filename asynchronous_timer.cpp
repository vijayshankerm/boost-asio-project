#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <asio.hpp>

using namespace std;

void print(const asio::error_code & /*e*/)
{
    std::cout << "Hello, world!" << std::endl;
}

int main()
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(1));
    cout << "Hello before wait \n";
    t.async_wait(&print);
    cout << "Hello after wait \n";
    io.run();
    return 0;
}
