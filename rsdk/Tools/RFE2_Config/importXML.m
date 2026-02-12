function xmlStruct = importXML(xmlFile)
    %Read the XML file
    xmlData = fileread(xmlFile);
    
    %Parse the XML data
    xmlDoc = xmlreadString(xmlData);
    
    %Create a structure from the parsed XML
    xmlStruct = xml2struct(xmlDoc);
end

function xmlDoc = xmlreadString(xmlString)
    %Create a temporary XML file from the XML string
    tempFile = tempname;
    tempFile = [tempFile '.xml'];
    fid = fopen(tempFile, 'w');
    fwrite(fid, xmlString);
    fclose(fid);

    %Read the temporary XML file using xmlread
    xmlDoc = xmlread(tempFile);
    
    %Delete the temporary XML file
    delete(tempFile);
end

function result = xml2struct(node)

    result = struct();
    
    % Get the attributes of the node
    attributes = node.getAttributes();
    
    if ~isempty(attributes)
        numAttributes = 0;
        attributeNode = attributes.item(numAttributes);
        while ~isempty(attributeNode)
            % Get the attribute name and value
            attrName = char(attributeNode.getName());
            attrValue = char(attributeNode.getValue());
            
            % If character contains ':' & '-', replace it with '_'
            attrName = strrep(attrName, ':', '_');
            attrName = strrep(attrName, '-', '_');
            
            % Add the attribute to the result struct
            result.(attrName) = attrValue;
            
            numAttributes = numAttributes + 1;
            attributeNode = attributes.item(numAttributes);
        end
    end
    
    %Get the child nodes
    childNodes = node.getChildNodes();
    numChildNodes = childNodes.getLength();
    
    %Process each child node
    for i = 0:numChildNodes-1
        childNode = childNodes.item(i);
        
        if childNode.getNodeType() == 1 % ELEMENT_NODE
            %Get the child node name and value
            nodeName = char(childNode.getNodeName());
            
            %Recursively process the child node
            childStruct = xml2struct(childNode);
            
            %Check if the node name already exists in the result struct
            if isfield(result, nodeName)
                %If the node name already exists, convert the result to a
                %cell array
                if ~iscell(result.(nodeName))
                    result.(nodeName) = {result.(nodeName)};
                end
                
                %Add the new value to the cell array
                result.(nodeName){end+1} = childStruct;
            else
                % If the node name does not exist, create a new field in
                % the result struct
                result.(nodeName) = childStruct;
            end
        end
    end
end