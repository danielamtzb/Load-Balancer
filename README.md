# Load-Balancer
CSCE 412 Cloud Computing Project 2 - Creating a Load Balancer

Learn how to model a simulation of a large company's load-balancing web requests using a load balancer.

This project will require a real-world implementation of a queue. Thsi will also need a struct, a lower-level data structure that allows data to be contained in an object.

Load balancers are available commercially, but in this project, you will build one that has:
● Requests - generates random IP addresses, both in and out, and random times for each request to be processed.
  o IP in
  o IP out
  o Time (integer)
● Webserver(s)
  o Takes requests from the Load Balancer
  o Process the requests
  o Asks for another
● Load Balancer
  o Queue of requests
  o Keeps track of time.
