/*
* Copyright (C) 2016 Turi
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <cppipc/cppipc.hpp>
#include "test_object_base.hpp"

int main(int argc, char** argv) {
  //cppipc::comm_server server({"localhost:2181"}, "test");
  cppipc::comm_server server({}, "","tcp://127.0.0.1:19000");
  /*
  cppipc::comm_server server({}, 
                             "",
                             "ipc:///tmp/cppipc_server_test");
                             */

  server.register_type<test_object_base>([](){ 
                                           return new test_object_impl;
                                         });
  server.start();
  getchar();
}
