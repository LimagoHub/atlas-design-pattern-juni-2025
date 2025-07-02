//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <stack>

namespace composite {

    class abstract_bank_node : public std::enable_shared_from_this<abstract_bank_node>{



    public:

        using AbstractNodeShared = std::shared_ptr<abstract_bank_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_bank_node>;
        using Children = std::vector<AbstractNodeShared>;



        explicit abstract_bank_node(std::string name = "undef"): name_{name}{}
        abstract_bank_node(const abstract_bank_node&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&) = delete;
        abstract_bank_node(const abstract_bank_node&&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&&) = delete;
        virtual ~abstract_bank_node() = default;


        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = abstract_bank_node;
            using pointer = AbstractNodeShared;  // or also value_type*
            using reference = abstract_bank_node&;  // or also value_type&

            Iterator(pointer ptr = nullptr)
                    : current_node(ptr)
            {
                if (current_node == nullptr)
                {
                    the_end();
                }
            }

            reference operator*() { return *current_node; }
            pointer operator->() { return current_node; }

            // Prefix increment
            Iterator& operator++()
            {
                if (!is_end())
                {
                    get_next_child();
                }
                return *this;
            }

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.current_node == b.current_node; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.current_node != b.current_node; };

        private:

            [[nodiscard]]
            auto is_end() const -> bool
            {
                return (current_node == nullptr);
            }

            auto the_end() -> void
            {

                depth = -1;
                current_node = nullptr;
            }

            [[nodiscard]]
            auto go_up_to(pointer ptr) -> bool
            {

                current_node = ptr;
                if (--depth <= 0)
                {
                    the_end();
                    return false;
                }
                return true;
            }

            auto go_down_to(pointer ptr) -> void
            {

                current_node = ptr;
                ++depth;
            }

            [[nodiscard]]
            auto get_parent() -> bool
            {
                parent_node = current_node->get_parent().lock();
                return (parent_node != nullptr);
            }

            [[nodiscard]]
            auto get_first_child_of_parent() -> bool
            {
                const auto& children = parent_node->get_children();
                if (!children.empty())
                {
                    go_down_to(children[0]);
                    return true;
                }
                return false;
            }

            [[nodiscard]]
            auto find_next_sibling() -> bool
            {
                const auto& children = parent_node->get_children();
                bool found{ false };
                for (auto& child : children)
                {
                    if (found)
                    {
                        current_node = child; // no depth change
                        return true;
                    }
                    found = (child == current_node);
                }
                return false;
            }

            [[nodiscard]]
            auto get_next_sibling() -> bool
            {
                if (depth > 0) // stop at root node
                {
                    if (get_parent())
                    {
                        if (find_next_sibling())
                        {
                            return true;
                        }
                    }
                }
                return false;
            }

            auto get_next_child() -> void
            {
                parent_node = current_node;
                if (!get_first_child_of_parent())
                {
                    while (!get_next_sibling())
                    {
                        if (!go_up_to(parent_node))
                        {
                            the_end();
                            break;
                        }
                    }
                }
            }

        private:
            int depth{ 0 };
            pointer current_node;
            pointer parent_node;
        };

        Iterator begin() { return Iterator(shared_from_this()); }
        Iterator end() { return Iterator(); }

        virtual  auto print(std::ostream& os) const  -> void {
            os << std::string{"name: "} << this->get_name();
        }

        friend auto operator<<(std::ostream &os, const abstract_bank_node &node)-> std::ostream & {
            node.print(os);
            return os;
        }

        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeWeak {
            return parent_;
        }

        auto set_parent(const AbstractNodeWeak &parent)->void {
            parent_ = parent;
        }

        virtual  auto get_children()const  -> Children {
            static Children dummy{};
            return dummy;
        }

        virtual void ausgabe() {
//            std::cout << *this << std::endl;
//            for(auto & item : get_children()) {
//                item->ausgabe();
//            }
            for(const auto & abstractNode: *this){
                std::cout << abstractNode << std::endl;
            }
        }



    private:
        AbstractNodeWeak parent_;
        std::string name_;



    };

} // composite
