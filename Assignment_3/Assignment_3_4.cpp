
/*
// 1 
// Computes the nth Fibonacci number using recursion.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(2^n), Space complexity: O(n) due to call stack.
int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
//正确性：该实现是正确的。
//特点：递归实现，时间复杂度为O(2^n)，空间复杂度为O(n)。 
//优点：简单易懂，代码量少，直观地反映了Fibonacci数列的定义。
//适用场景：适用于小规模数据。
//新语法/算法细节：无。

// 2 
// Computes the nth Fibonacci number using iteration.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//正确性：该实现是正确的。
//特点：使用循环代替递归，迭代实现，时间复杂度为O(n)，空间复杂度为O(1)。
//优点：效率高，时间复杂度低。
//适用场景：适用于大规模数据。
//新语法/算法细节：无。



//3 
// Computes the nth Fibonacci number using dynamic programming.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n).
#include <vector>
int fibonacci_dp(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//正确性：该实现是正确的。
//特点：动态规划实现，时间复杂度为O(n)，空间复杂度为O(n)。
//优点：效率高，时间复杂度低。
//适用场景：适用于大规模数据。
//新语法/算法细节：动态规划。



//4 
// Computes the nth Fibonacci number using matrix exponentiation.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(log n), Space complexity: O(1).
#include <array>
std::array<std::array<long long, 2>, 2> matrix_multiply(const
std::array<std::array<long long, 2>, 2>& a, const std::array<std::array<long long,2>, 2>& b) {
    std::array<std::array<long long, 2>, 2> result = {{0}};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}
long long fibonacci_matrix(int n) {
    if (n <= 1) return n;
    std::array<std::array<long long, 2>, 2> base = {{1, 1}, {1, 0}};
    std::array<std::array<long long, 2>, 2> result = {{1, 0}, {0, 1}};
    n--;
    while (n > 0) {
        if (n & 1) result = matrix_multiply(result, base);
        base = matrix_multiply(base, base);
        n >>= 1;
    }
    return result[0][0];
}
//正确性：该实现是正确的。
//特点：矩阵幂实现，时间复杂度为O(log n)，空间复杂度为O(1)。
//优点：效率极高，时间复杂度和空间复杂度低。
//适用场景：适用于大规模数据。
//新语法/算法细节：使用了矩阵运算，使用array固定大小数组，使用位运算优化。


// 5 
// Computes the nth Fibonacci number using memoization.
// @param n The index of the Fibonacci number to compute.
// @param memo A reference to an unordered_map to store computed Fibonacci numbers.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n) due to memoization.
#include <unordered_map>
long long fibonacci_memoization(int n, std::unordered_map<int, long long>&memo) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    memo[n] = fibonacci_memoization(n - 1, memo) +fibonacci_memoization(n - 2, memo);
    return memo[n];
}
//正确性：该实现是正确的。
//特点：记忆化递归实现，使用哈希表存储中间结果，时间复杂度为O(n)，空间复杂度为O(n)。
//优点：效率高，时间复杂度和空间复杂度低。
//适用场景：适合需要多次计算不同n的Fibonacci数的场景。
//新语法/算法细节：使用记忆化搜索，避免了重复计算；使用unordered_map存储中间结果。


// 6 
// Computes the nth Fibonacci number safely, returning std::nullopt for negative inputs.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number or std::nullopt if n is negative.
// @note Time complexity: O(n), Space complexity: O(1). 
#include <optional>
std::optional<long long> fibonacci_safe(int n) {
    if (n < 0) return std::nullopt;
    if (n <= 1) return n;
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//正确性：该实现是正确的。
//特点：使用std::optional处理无效输入，时间复杂度为O(n)，空间复杂度为O(1)。
//优点：效率高，时间复杂度和空间复杂度低。
//适用场景：适合需要严格输入检查的场景。
//新语法/算法细节：使用了std::optional。


// 7 
// Computes the nth Fibonacci number using constexpr.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1). 
constexpr long long fibonacci_constexpr(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//正确性：该实现是正确的。
//特点：使用constexpr关键字，时间复杂度为O(n)，空间复杂度为O(1)。
//优点：可以在编译期计算Fibonacci数，提高运行时效率。
//适用场景：适合需要编译期常量的场景。
//新语法/算法细节：使用了constexpr关键字。 


// 8 
// Computes the nth Fibonacci number using parallel execution.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(n) due to async calls.
#include <future>
long long fibonacci_parallel(int n) {
    if (n <= 1) return n;
    auto future = std::async(std::launch::async, fibonacci_parallel, n - 2);
    long long result = fibonacci_parallel(n - 1);
    return result + future.get();
}
//正确性：该实现是正确的。
//特点：并行实现，时间复杂度为O(n)，空间复杂度为O(n)。
//优点：可以利用多核处理器提高性能。
//适用场景：适合大规模计算且有多核处理器的场景。
//新语法/算法细节：使用了std::async和std::future。


// 9 
// Computes the nth Fibonacci number using bigint.
// @param n The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
#include <boost/multiprecision/cpp_int.hpp>
boost::multiprecision::cpp_int fibonacci_bigint(int n) {
    if (n <= 1) return n;
    boost::multiprecision::cpp_int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
 return b;
}
//正确性：该实现是正确的。
//特点：使用Boost库的大整数类型，时间复杂度为O(n)，空间复杂度为O(1)。
//优点：可以计算非常大的Fibonacci数而不会溢出。
//适用场景：适合需要计算大规模Fibonacci数的场景。
//新语法/算法细节：使用了Boost库的cpp_int类型。 


// 10 
// Computes the nth Fibonacci number using template metaprogramming.
// @param N The index of the Fibonacci number to compute.
// @return The nth Fibonacci number.
// @note Time complexity: O(n), Space complexity: O(1).
template<int N, typename = std::enable_if_t<(N >= 0)>>
struct Fibonacci {
    static constexpr long long value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};
template<>
struct Fibonacci<0> {
    static constexpr long long value = 0;
};
template<>
struct Fibonacci<1> {
    static constexpr long long value = 1;
};
//正确性：该实现是正确的。
//特点：使用模板元编程，时间复杂度为O(n)，空间复杂度为O(1)。
//优点：在编译期计算Fibonacci数，运行时零开销。
//适用场景：适合需要编译期常量的场景。
//新语法/算法细节：使用模板元编程。   
*/


// 结合迭代和模版元，运行时计算和编译期计算双重功能。 
// 在主函数部分进行输入错误处理。 
#include <iostream>
class Fibonacci {
public:
    // Runtime calculation
    static long long get(int n) {
        if (n <= 1) return n;
        
        long long a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            long long temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    // Compile-time calculation
    template<int N>
    static constexpr long long constant() {
        if constexpr (N <= 1) {
            return N;
        } else {
            return constant<N-1>() + constant<N-2>();
        }
    }
};
int main() {
	
	std::cout << "Please choose the calculation method:"<<std::endl;
    std::cout << "1. Runtime calculation"<<std::endl;
    std::cout << "2. Compile-time calculation"<<std::endl;
    
    int choice;
    std::cin >> choice;
    if(std::cin.fail()||(choice!=1&&choice!=2)){
    	std::cout << "Wrong Input"<<std::endl;
    	return -1;
	}
    
	if(choice==1){
		// Runtime computation
		// Runtime calculations can use variables
		std::cout << "Please enter the index of the Fibonacci number to calculate(1-92): ";
	    int n;
	    std::cin>>n;
	    if(std::cin.fail()||n<1||n>92){
    	    std::cout << "Wrong Input"<<std::endl;
    	    return -1;
	    }
        std::cout << "F(" << n << ") = " << Fibonacci::get(n) << std::endl;
	}else{
		// Compile-time computation
		// Compile-time calculations can only use predefined values
		constexpr int N = 10;
        constexpr auto compile_time_result = Fibonacci::constant<N>();
        std::cout << "Compile-time F(" << N << ") = " << compile_time_result << std::endl;
	}
	
    return 0;
}


