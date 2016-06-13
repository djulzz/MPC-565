function setup(block)

%% Register a single dialog parameter
block.NumDialogPrms  = 2;

%% Register number of input and output ports
block.NumInputPorts  = 2;
block.NumOutputPorts = 0;

%% Setup functional port properties to dynamically
%% inherited.
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

%% Hard-code certain port properties
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DirectFeedthrough = true;


%% Set block sample time to inherited
block.SampleTimes = [-1 -1];

%% Register methods
block.RegBlockMethod('Update',              @Update);
block.RegBlockMethod('PostPropagationSetup',@DoPostPropSetup);


function DoPostPropSetup(block)

  %% Setup Dwork
  block.NumDworks = 2;
  block.Dwork(1).Name = 'cIndex'; 
  block.Dwork(1).Dimensions      = 1;
  block.Dwork(1).DatatypeID      = 0;
  block.Dwork(1).Complexity      = 'Real';
  block.Dwork(1).UsedAsDiscState = true;
  
  block.Dwork(2).Name = 'cByte'; 
  block.Dwork(2).Dimensions      = 1;
  block.Dwork(2).DatatypeID      = 0;
  block.Dwork(2).Complexity      = 'Real';
  block.Dwork(2).UsedAsDiscState = true;