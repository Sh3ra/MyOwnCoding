function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
y_=zeros(size(y,1),num_labels);
for i=1:size(y,1)
  y_(i,y(i))=1;
endfor
y=y_;
X = [ones(m, 1) X];
a2=zeros(1,size(Theta1,1));
a3=zeros(1,size(y,2));

for i=1:size(X,1)
  a2=sigmoid(X(i,:)*Theta1');
  a2=[ones(size(a2), 1) a2];
  a3=sigmoid(a2*Theta2');
  for j=1:size(y,2)
    J=J+((-y(i,j))*log(a3(j))-(1-y(i,j))*log(1-a3(j)));  
  endfor
endfor
J=J/m;
t1_reg=0;
for i=1:size(Theta1,1)
  for j=2:size(Theta1,2)
      t1_reg=t1_reg+Theta1(i,j)^2;
  endfor
endfor
t2_reg=0;
for i=1:size(Theta2,1)
  for j=2:size(Theta2,2)
      t2_reg=t2_reg+Theta2(i,j)^2;
  endfor
endfor
J=J+(lambda/(2*m))*(t1_reg+t2_reg);
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
delta3=zeros(size(a3));
delta2=zeros(size(a2));
for i=1:m
  a2=sigmoid(X(i,:)*Theta1');
  a2=[ones(size(a2), 1) a2];
  a3=sigmoid(a2*Theta2');
  delta3=a3-y(i,:);
  delta3=delta3';
  errorWbias=Theta2'*delta3;
  errorWbias=errorWbias(2:end)';
  delta2=errorWbias.*sigmoidGradient(X(i,:)*Theta1');
  delta2=delta2';
  Theta2_grad=Theta2_grad+delta3*a2;
  Theta1_grad=Theta1_grad+delta2*(X(i,:));
endfor
t1=0;
t2=0;
for i=1:size(Theta1_grad,1)
  for j=1:size(Theta1_grad,2)
      if (j>1)
        Theta1_grad(i,j)=Theta1_grad(i,j)+(lambda)*Theta1(i,j);
      endif
      Theta1_grad(i,j)=Theta1_grad(i,j)/m;
  endfor
endfor
for i=1:size(Theta2_grad,1)
  for j=1:size(Theta2_grad,2)
      if (j>1)
        Theta2_grad(i,j)=Theta2_grad(i,j)+(lambda)*Theta2(i,j);
      endif
      Theta2_grad(i,j)=(Theta2_grad(i,j)/m);
  endfor
endfor

% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%



















% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
