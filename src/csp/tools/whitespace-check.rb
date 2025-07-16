#!/usr/bin/env ruby

def check_file(fpath)
  IO.foreach(fpath).with_index do |line, idx|
    line = line.chomp
    if line =~ /^(\s*).*?(\s*)$/
      leading, tailing = $1, $2
      if leading.index("\t")
        puts "#{fpath}:#{idx+1} tab in leading space"
      end
      if tailing.length > 0
        puts "#{fpath}:#{idx+1} tailing space"
        #puts "  orig: '#{line}'"
        #puts "  tailing: '#{tailing}'"
      end
    end
  end
end

# main
ARGV.each { |arg| check_file(arg) }
