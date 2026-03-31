#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <memory>
#include <string>
#include <complex>
#include <Eigen/Dense>

class Component {
protected:
    std::complex<double> impedance;
    int id;
public:
    Component();
    ~Component();
    static int next_id; // Static member to keep track of the next available ID
    int get_id() const;
    std::complex<double> get_impedance() const;
};

class Resistor : public Component {
public:
    Resistor(double resistance);
    void set_resistance(double resistance);
};

class Capacitor : public Component {
private:
    double frequency{60}; // Frequency in Hz for impedance calculation
public:
    Capacitor(double capacitance);
    void set_capacitance(double capacitance);
};

class Inductor : public Component {
private:
    double frequency{60}; // Frequency in Hz for impedance calculation  
public:
    Inductor(double inductance);
    void set_inductance(double inductance);
};

class Node {
private:
    int id;
    static int next_id; // Static member to keep track of the next available ID
public:
    Node();
    ~Node();
    int get_id() const;
};

struct Connection {
    std::shared_ptr<Component> component;
    std::shared_ptr<Node> node1;
    std::shared_ptr<Node> node2;
};

class BreadBoard {
private:
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<Connection> connections;

    std::vector<std::vector<std::complex<double>>> incidence_matrix;
    std::vector<std::vector<std::complex<double>>> impedance_matrix;

public:
    BreadBoard();
    ~BreadBoard();
    void add_node(std::shared_ptr<Node> node);
    void add_component(std::shared_ptr<Component> component, std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);


};

#endif // COMPONENT_H