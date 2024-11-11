add_executable(echo_client EchoClient.cc)
target_link_libraries(echo_client goa-ev)

add_executable(echo_server EchoServer.cc)
target_link_libraries(echo_server goa-ev)

add_executable(addOne_server AddOneServer.cc)
target_link_libraries(addOne_server goa-ev)

add_executable(addOne_client AddOneClient.cc)
target_link_libraries(addOne_client goa-ev)