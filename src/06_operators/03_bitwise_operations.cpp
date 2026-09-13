#include <bitset>
#include <cstdint>


int main()
{
    std::bitset<8> bits { 0b0000'0101 };
    bits.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);  // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits<< '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    [[maybe_unused]] constexpr int  isHungry   { 0 };
    [[maybe_unused]] constexpr int  isSad      { 1 };
    [[maybe_unused]] constexpr int  isMad      { 2 };
    [[maybe_unused]] constexpr int  isHappy    { 3 };
    [[maybe_unused]] constexpr int  isLaughing { 4 };
    [[maybe_unused]] constexpr int  isAsleep   { 5 };
    [[maybe_unused]] constexpr int  isDead     { 6 };
    [[maybe_unused]] constexpr int  isCrying   { 7 };

    std::bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
    me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
    me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    std::cout << bits.size() << " bits are in the bitset\n";
    std::cout << bits.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << bits.all() << '\n';
    std::cout << "Some bits are true: " << bits.any() << '\n';
    std::cout << "No bits are true: " << bits.none() << '\n';

    // Bitwise operators
    std::bitset<4> x { 0b1100};

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n';
    std::cout << (x << 1) << '\n';

	std::bitset<4> y { 0b0110 };

	std::cout << y << 1 << '\n'; // print value of y (0110), then 1
	std::cout << (y << 1) << '\n'; // print y left shifted by 1 (1100)

    std::cout << ~y << '\n';

    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110}) << '\n';

    std::cout << (std::bitset<4>{ 0b0001 } & std::bitset<4>{ 0b0011 } & std::bitset<4>{ 0b0111 }) << '\n';

    // Mask operations
    // Defined as symbolic constants
    [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // bit 0
    [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // bit 1
    [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // bit 2
    [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // bit 3
    [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // bit 4
    [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // bit 5
    [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // bit 6
    [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // bit 7

    std::uint8_t flags{ 0b0000'0101 };
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
    return 0;
}