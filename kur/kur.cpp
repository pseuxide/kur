#include "kur.h"

auto main() -> int
{
  if (!vul_driver::install_driver())
  {
    std::cerr << "couldn't deploy the driver" << std::endl;
    return 1;
  }
  do
  {
    auto status = vul_driver::setup_registry_key();
    if (!status)
    {
      std::cerr << "couldn't setup the registry" << std::endl;
      break;
    }
    status = vul_driver::service_start();
    if (!status)
    {
      std::cerr << "couldn't start the service" << std::endl;
      break;
    }
  }
  while (false);
  std::cout << "driver is loaded correctly." << std::endl;
  //vul_driver::delete_registry_key();
  //_wremove(vul_driver::get_full_driver_path().c_str());
  std::cin.get();
  return 0;
}
