def processFeature(feature, featuresEnabled, sources, featureList, verbose):
    if verbose:
        print(f"  Processing feature {feature}")

    if feature not in featuresEnabled:
        featuresEnabled.append(feature)

    if feature in featureList:
        for source in featureList[feature]['SOURCES']:
            if source not in sources:
                sources.append(source)
                if verbose:
                    print(f"    Adding source file {source}")

        for dependency in featureList[feature]['DEPENDENCIES']:
            if dependency not in featuresEnabled:

                if verbose:
                    print(f"    Enabling dependency {dependency}")

                featuresEnabled, sources = processFeature(dependency, featuresEnabled, sources, featureList, verbose)
    else:
        pass
        # TODO: save this info somewhere and pass it back. We can later use this to make sure that all features have been found somewhere

    return featuresEnabled, sources
