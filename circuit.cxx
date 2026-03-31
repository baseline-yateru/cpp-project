#include "circuit.h"
///////////////////////////////////////////////////// Components /////////////////////////////////////////////////////
int Component::next_id = 0; // Initialize static member
Component::Component() {
    // Initialize impedance to zero
    impedance = std::complex<double>(0.0, 0.0);
    id = next_id++; // Assign a unique ID to the component
}
Component::~Component() {
    // Destructor can be used for cleanup if needed
}
int Component::get_id() const {
    return id;
}
std::complex<double> Component::get_impedance() const {
    return impedance;
}

////////////////////////////////////////////////////// Resistors /////////////////////////////////////////////////////
Resistor::Resistor(double resistance) : Component(){
    // Set impedance for a resistor (purely real)
    impedance = std::complex<double>(resistance, 0.0);
}
void Resistor::set_resistance(double resistance) {
    impedance = std::complex<double>(resistance, 0.0);
}
///////////////////////////////////////////////////// Capacitors /////////////////////////////////////////////////////
Capacitor::Capacitor(double capacitance) : Component() {
    // Set impedance for a capacitor (purely imaginary, negative)
    impedance = std::complex<double>(0.0, -1.0 / (2 * M_PI * frequency * capacitance)); // Assuming 60 Hz frequency
}
void Capacitor::set_capacitance(double capacitance) {
    impedance = std::complex<double>(0.0, -1.0 / (2 * M_PI * frequency * capacitance));
}

////////////////////////////////////////////////////// Inductors /////////////////////////////////////////////////////
Inductor::Inductor(double inductance) : Component() {
    // Set impedance for an inductor (purely imaginary, positive)
    impedance = std::complex<double>(0.0, 2 * M_PI * frequency * inductance); // Assuming 60 Hz frequency
}
void Inductor::set_inductance(double inductance) {
    impedance = std::complex<double>(0.0, 2 * M_PI * frequency * inductance);
}
//////////////////////////////////////////////////////// Nodes ///////////////////////////////////////////////////////
int Node::next_id = 0; // Initialize static member
Node::Node() {
    id = Node::next_id++; // Assign a unique ID to the node
}
Node::~Node() {
    // Destructor implementation
}
int Node::get_id() const {
    return id;
}
////////////////////////////////////////////////////// BreadBoard ////////////////////////////////////////////////////
BreadBoard::BreadBoard() {
    // Constructor implementation
}
BreadBoard::~BreadBoard() {
    // Destructor implementation
}

void BreadBoard::add_component(std::shared_ptr<Component> component, std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) {
    connections.push_back({component, node1, node2});
    components.push_back(component);
}
