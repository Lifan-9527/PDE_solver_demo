% Formular

classdef Formular
    properties
        name;
	id;

	highest_order;
	dim;
	coef;
	order;
    end
    methods
        function self = Formular()
    
        end
    
        function LoadConfig()
        end
    
        function Print()
        end
    end
end


classdef Equations
    properties
        eqNum;
	dim;
	highest_order;
	equations
    end
    methods

    end

end
