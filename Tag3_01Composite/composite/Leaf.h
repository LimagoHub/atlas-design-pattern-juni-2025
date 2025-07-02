//
// Created by JoachimWagner on 02.07.2025.
//

#pragma once
// Konto
#include "AbstractNode.h"
class Leaf :public AbstractNode{
public:
    using AbstractNode::AbstractNode;
    void print(std::ostream &os) const override {
        os << std::string{"Leaf: "};
        AbstractNode::print(os);
    }
private:
    double saldo{0};
};
