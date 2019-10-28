def find_uniq(arr)
  new_arr = arr.dup
  match = new_arr.uniq[1]
  alt = new_arr.uniq[0]
  count = 0
  arr.each do |x|
    unless x == match
      count += 1
    end
  end
  if count > 1
    match
  else
    alt
  end
end
