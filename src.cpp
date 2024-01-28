#include <iostream>
#include <string>
#include <boost/program_options.hpp>

int main(int argc, char* argv[]) {
  boost:program_options::options_description option("オプション");
  option.add_options()
    ("help,h", "ヘルプを表示")
    ("name,n", boost::program_options::value(), "名称")
    ("count,c", boost::program_options::value()->default_value(10), "カウント")
    ("flag,f", boost::program_options::value(), "フラグ");

  boost:program_options::variables_map vm;
  try {
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, option), vm);
  } catch ( const boost::program_options::error_with_option_name& e ) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  boost::program_options::notify(vm);

  if ( vm.count("help") ) {
    std::cout << option << std::endl;
  }

  if ( vm.count("name") ) {
    try {
      const std::string name = vm["name"].as();
      std::cout << name << std::endl;
    } catch ( const boost::bad_any_cast& e ) {
      std::cout << e.what() << std::endl;
    }
  }

  const int count = vm["count"].as();
  std::cout << count << std::endl;

  if ( vm.count("flag") ) {
    try {
      const bool flag = vm["flag"].as();
      std::cout << flag << std::endl;
    } catch ( const boost::bad_any_cast& e ) {
      std::cout << e.what() << std::endl;
    }
  }
  
  return 0;
}
