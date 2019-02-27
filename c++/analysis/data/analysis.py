from numpy import sqrt

def my_mean(i_data):
    sum=0.0
    for i in i_data:
        sum += i;
    return sum/len(i_data)

def my_dev(i_data):
    sum=0.0
    av = my_mean(i_data)
    for i in i_data:
        sum += ((i-av)**(2))
    return sqrt(sum/(len(i_data)-1))

def my_err_mean(i_data):
    std_dev = my_dev(i_data)
    return std_dev/sqrt(len(i_data))
