#include <experimental/filesystem>
#include <iostream>
#include <cstdlib>
#include <fstream>

// https://en.cppreference.com/w/cpp/header/experimental/filesystem

// g++ filesystem.cpp -lstdc++fs

namespace fs = std::experimental::filesystem;

void print_perms(fs::perms p) {
    std::cout << ( (p & fs::perms::owner_read)  != fs::perms::none ? "r" : "-" )
              << ( (p & fs::perms::owner_write) != fs::perms::none ? "w" : "-" )
              << ( (p & fs::perms::owner_exec)  != fs::perms::none ? "x" : "-" )
              << ( (p & fs::perms::group_read)  != fs::perms::none ? "r" : "-" )
              << ( (p & fs::perms::group_write)  != fs::perms::none ? "w" : "-" )
              << ( (p & fs::perms::group_exec)  != fs::perms::none ? "x" : "-" )
              << ( (p & fs::perms::others_read)  != fs::perms::none ? "r" : "-" )
              << ( (p & fs::perms::others_write)  != fs::perms::none ? "w" : "-" )
              << ( (p & fs::perms::others_exec)  != fs::perms::none ? "x" : "-" )
              << std::endl;
}

void print_filetype(const fs::file_type& ft, const fs::path& p) {
    switch (ft) {
        case fs::file_type::regular:
            std::cout << p << " ist eine reguläre Datei\n";
            break;
        case fs::file_type::directory:
            std::cout << p << " ist ein Verzeichnis\n";
            break;
        case fs::file_type::symlink:
            std::cout << p << " ist ein Symlink\n";
            break;
        case fs::file_type::block:
            std::cout << p << " ist eine Block-Gerätedatei\n";
            break;
        case fs::file_type::character:
            std::cout << p << " ist eine Zeichen-Gerätedatei\n";
            break;
        case fs::file_type::fifo:
            std::cout << p << " ist eine FIFO (named pipe)\n";
            break;
        case fs::file_type::socket:
            std::cout << p << " ist eine Socket-Datei\n";
            break;
        case fs::file_type::none:
            std::cout << p << " existiert nicht\n";
            break;
        case fs::file_type::not_found:
            std::cout << p << " wurde nicht gefunden\n";
            break;
        default:
            std::cout << p << " hat einen unbekannten Dateityp\n";
            break;
    }
}

int main() {

    fs::path f = fs::current_path();

    if(fs::exists(f))
        std::cout<<"f exists\n";
    if(fs::is_directory(f))
        std::cout<<"f is a directory\n";
    else
        std::cout<<"f is a file\n";

    std::cout<<f<<std::endl;

    for(auto& entry : fs::recursive_directory_iterator(f)) {
        if (entry.path().extension() == ".cpp" && fs::is_regular_file(entry.path())) {
            fs::file_status st = fs::status(entry);
            std::cout<<entry<<"   ";
            print_perms(st.permissions());
            fs::file_type ft = st.type();
            print_filetype(ft, entry);
        }
    }

    std::cout<<"create directories\n";
    fs::create_directories("sandbox/1/2/a");
    fs::create_directory("sandbox/1/2/b");
    std::system("ls -l sandbox/1/2");
    fs::permissions("sandbox/1/2/b", fs::perms::remove_perms | fs::perms::others_all);
    std::system("ls -l sandbox/1/2");
    fs::create_directory("sandbox/1/2/c", "sandbox/1/2/b");
    std::system("ls -l sandbox/1/2");
    fs::remove_all("sandbox");



    fs::create_directory("sandbox");
    std::ofstream("sandbox/file1.txt").put('a');
 
    fs::copy_file("sandbox/file1.txt", "sandbox/file2.txt");
 
    // now there are two files in sandbox:
    std::cout << "file1.txt holds : "
              << std::ifstream("sandbox/file1.txt").rdbuf() << '\n';
    std::cout << "file2.txt holds : "
              << std::ifstream("sandbox/file2.txt").rdbuf() << '\n';
    
    std::cout << "File size = " << fs::file_size("sandbox/file2.txt") << '\n';

    // fail to copy directory
    fs::create_directory("sandbox/abc");
    try
    {
        fs::copy_file("sandbox/abc", "sandbox/def");
    }
    catch (fs::filesystem_error& e)
    {
        std::cout << "Could not copy sandbox/abc: " << e.what() << '\n';
    }
    fs::remove_all("sandbox");

    try
    {
        fs::file_size("/dev"); // attempt to get size of a directory
    }
    catch (fs::filesystem_error& e)
    {
        std::cout << e.what() << '\n';
    } 

    fs::space_info devi = fs::space("/dev/null");
    fs::space_info tmpi = fs::space("/tmp");
 
    std::cout << "         Capacity         Free    Available\n"
              << "/dev:   " << devi.capacity/1048576 << "   "
              << devi.free/1048576 << "   " << devi.available/1048576 << '\n'
              << "/tmp: " << tmpi.capacity/1048576 << ' '
              << tmpi.free/1048576 << ' ' << tmpi.available/1048576 << '\n';


    fs::path p = fs::current_path() / "sandbox";
    fs::create_directories(p/"from");
    std::ofstream(p/"from/file1.txt").put('a');
    fs::create_directory(p/"to");
 
//  fs::rename(p/"from/file1.txt", p/"to/"); // error: to is a directory
    fs::rename(p/"from/file1.txt", p/"to/file2.txt"); // OK
//  fs::rename(p/"from", p/"to"); // error: to is not empty
    fs::rename(p/"from", p/"to/subdir"); // OK
 
    fs::remove_all(p);
    return 0;
}