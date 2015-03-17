#pragma once

namespace LibTest_runner
{
#pragma warning ( push )
#pragma warning( disable : 4290 )
  using namespace Windows::Data::Xml::Dom;
  using namespace Platform;

  //=============================================================================
  //         class: CXmlReporter
  //   Description: Test reporter generating xml file
  //              
  // History: 
  // 2015/03/09 TP: created
  //=============================================================================
  class CXmlReporter : public CTestsReporterBase
  {
  private:
    Platform::String^ OutputFile_;
    XmlDocument^ report_;
    XmlElement^  solutionEl_;
    XmlElement^ GetLibraryElement(String^ projectName);
    XmlElement^ GetProjectElement(XmlElement^ library, String^ projectName);
  public:
    CXmlReporter(Platform::String^ outputFile);
    virtual ~CXmlReporter() {};
    virtual void AddTestResult(const CTestBase& test) throw(ReportGenerationException);
    virtual void Begin() throw(ReportGenerationException);
    virtual void AddTestSolutionHeader(const CTestSolution& solution) throw(ReportGenerationException);
    virtual void End() throw(ReportGenerationException);
  };

  typedef std::shared_ptr<CXmlReporter> SpXmlReporter_t;

#pragma warning ( pop )
}


