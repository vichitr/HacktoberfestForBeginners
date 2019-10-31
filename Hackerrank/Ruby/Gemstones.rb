# URL: https://www.hackerrank.com/challenges/gem-stones/

n = gets.strip.to_i
arr = Array.new
n.times do
  arr << gets.strip
end

result = 0

arr[0].chars.to_a.uniq.to_s.each_char do |chr|
  common = true
  arr.each do |x|
    unless x.index(chr)
      common = false
      break
    end
  end
  result += 1 if common
end

print result
