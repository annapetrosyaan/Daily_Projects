import string
from unicodedata import name
import numpy as np
import random
from matplotlib import pyplot as plt
from math import sqrt, pow


class Histogram:
    def __init__(self, name, nbins, xlow, xup):
        self.name = name
        self.bins = nbins
        self.xlow = xlow
        self.xup = xup
        self.hist = np.zeros(self.bins)

    def get_bin(self,x) -> None :
        n = int(np.ceil(self.get_bin_width()))
        minimum = self.xlow
        big = minimum + n
        level=1
        while(minimum <= self.xup):
            if x >= minimum and x < big:
                return level
            minimum = big
            big += n
            level += 1
      
    def get_bin_width(self):
        return (self.xup-self.xlow) / self.bins
      
    def get_bin_center(self, x):
        return self.xlow + (x-1) * self.get_bin_width() +self.get_bin_width()/2
     
    def get_bin_content(self, i):
        return self.hist[i]
  
    def fill(self, x):
        level = 0
        n = int(np.ceil(self.get_bin_width()))
        for i in range(self.xlow, self.xup+1, n):
           if i == 0:
               if x >= i and x <= i+n:
                   self.hist[level] += 1
           elif x>i & x <= i+n:
                self.hist[level] += 1
           level = level + 1
    def get_std(self):
      sum = 0
      mean = self.get_mean()
      for i in self.hist:
            sum = sum+pow ((i-mean),2)
      res = 1/self.bins * sum
      return sqrt(res)
  
    def draw_graph(self, fname: str)->None:
        bins = np.zeros(self.bins)
        widths = np.zeros(self.bins)
        for i in range(self.bins):
            bins[i] = self.get_bin_center(i)
            widths[i] = self.get_bin_width()
        plt.bar(bins, self.hist, widths)
        plt.title(self.name)
        plt.savefig(fname)
 
    def get_mod(self):
        return max(set(self.hist), key = list(self.hist).count)
    
    def get_mean(self):
        return self.hist.sum() / self.bins
  
    def get_integral(self):
        return (self.xup - self.xlow) * self.get_mean()

    def get_minimum(self):
        return min(self.hist)

    def get_maximum_bin(self):
        max=0
        n = int(np.ceil(self.get_bin_width()))
        for i in range(n+1):
            if self.hist[i] > max:
                max = self.hist[i]
                maxindex = i
        return maxindex + 1

    def assign(self, hist2):
        if(self.bins == hist2.bins):
            for i in range(0, len(hist2.hist)):
                self.hist[i] = hist2.hist[i]
        else:
            print("Sizes differ")

