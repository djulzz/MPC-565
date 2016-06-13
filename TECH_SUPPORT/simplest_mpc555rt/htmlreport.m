function htmlreport
    OldFiles=[];
    if cmpTimeFlag('htmlreport.m', '..\simplest_flash.map') <= 0
      OldFiles=[OldFiles ' ..\simplest_flash.map'];
    end
    if cmpTimeFlag('htmlreport.m', '..\simplest_flash.elf') <= 0
      OldFiles=[OldFiles ' ..\simplest_flash.elf'];
    end
    if ~isempty(OldFiles)
      error(['### Detected target build failure. Map and/or program file(s) are not up-to-date.'])
    end
function result = cmpTimeFlag(file1, file2)
  
    record1 = dir(eval('file1'));
      [row col] = size(record1);
      if (row == 0) | (col == 0)
        result = 0;
        return
      end
    record2 = dir(eval('file2'));
      [row col] = size(record2);
      if (row == 0) | (col == 0)
        result = 0;
        return
      end    
    date1 = datevec(record1.datenum);

    match_file_num = row;
    for loop = 1:match_file_num
      date2 = datevec(record2(loop).datenum);
      for i = 1:6
        if date1(i) < date2(i)
          result = 1;
          return
        elseif date1(i) > date2(i)
          result = -1;
          if (loop == match_file_num)
            return
          else
            break
          end
        else
        end
      end
    end
    result = 0;

function profileHouseKeeping
    if exist('simplest_gen_file_list.txt')
      delete('simplest_gen_file_list.txt');
    end
  
